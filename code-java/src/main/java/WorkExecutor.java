import com.google.common.base.Throwables;
import com.google.common.collect.Lists;
import org.apache.commons.lang3.RandomStringUtils;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.slf4j.LoggerFactory;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.concurrent.CompletionService;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorCompletionService;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadFactory;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.function.Function;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;

public class WorkExecutor {

    private final MathService mathService;
    private final ConcurrentWorkExecutor concurrentWorkExecutor;
    private static final org.slf4j.Logger log = LoggerFactory.getLogger(WorkExecutor.class);

    public WorkExecutor(MathService mathService, ConcurrentWorkExecutor concurrentWorkExecutor) {
        this.mathService = mathService;
        this.concurrentWorkExecutor = concurrentWorkExecutor;
    }

    public List<Integer> processExpensiveFunction(List<Integer> inputs, int firstK) {
        try {
            List<Integer> outputs = new ArrayList<>();
            ExecutorService executor = Executors.newCachedThreadPool();
            ExecutorCompletionService<Integer> executorService = new ExecutorCompletionService<>(executor);

            for (Integer input : inputs) {
                executorService.submit(() -> {
                    log.info("Submitting task f({}) on {}", input, Thread.currentThread().getName());
                    return mathService.process(input);
                });
            }
            executor.shutdown();
            for (int outputCount = 1; outputCount <= firstK; outputCount++) {
                Integer output = executorService.take().get();
                log.info("Finished {}/{}: {} on {}", outputCount, firstK, output, Thread.currentThread().getName());
                outputs.add(output);
            }
            return outputs;

        } catch (Exception ex) {
            log.error("Error processing expensive function");
            return null;
        }
    }

    public List<Integer> processExpensiveFunctionElegant(List<Integer> inputs, int firstK) {
        try {
            return concurrentWorkExecutor.splitJoin(firstK,
                    inputs,
                    mathService::process,
                    Collectors.toList());

        } catch (Exception ex) {
            log.error("Error processing expensive function", ex);
            return null;
        }
    }

    interface MathService {

        /**
         * Process an expensive function f(x) on a given integer and returns the result.
         */
        Integer process(Integer X);
    }

    static class RemoteMathService implements MathService {

        private final Random delay = new Random();

        @Override
        public Integer process(Integer X) {
            try {
                TimeUnit.MILLISECONDS.sleep(delayIteration());
            } catch (InterruptedException ignored) {
            }
            return X;
        }

        private long delayIteration() {
            return 100L * delay.nextInt(10);
        }
    }

    interface ConcurrentWorkExecutor {

        /**
         * Splits a work iterable and submits each task into an executor where the task input is obtained by
         * applying a mapper function. The intermediate non null results are joined until a {@code size} number
         * of results are obtained post which they are collected using a custom user defined collector.
         *
         * @param size      the number of results to wait for
         * @param iterable  the work represented as an iterable
         * @param mapper    the transformation of individual item U within the iterable to a result T
         * @param collector the collection of T results obtained into a custom collector of type V
         * @return an object of type V which is obtained after collection of intermediate T type results
         * @implNote - If all intermediate results are required before collecting the final result, {@code size}
         * must be equal to the number of items represented by the iterable
         */
        <T, U, V> V splitJoin(int size,
                              Iterable<U> iterable,
                              Function<U, T> mapper,
                              Collector<T, ?, V> collector) throws ExecutionException, InterruptedException;
    }

    /**
     * A concurrent work executor that blocks for the final result after individual execution results
     * are obtained. The results are fed into the queue represented by completion service as they are
     * getting completed. Note that this behavior can be changed by using a single threaded executor
     * <p>
     * If execution of any individual work results in an exception, an exception is raised
     */
    static class OutOfOrderConcurrentWorkExecutor implements ConcurrentWorkExecutor {

        @Override
        public <T, U, V> V splitJoin(int size, Iterable<U> iterable, Function<U, T> mapper, Collector<T, ?, V> collector) throws ExecutionException, InterruptedException {
            ThreadFactory threadFactory = Executors.defaultThreadFactory();
            ExecutorService executor = Executors.newCachedThreadPool(threadFactory);  //create a cached thread pool ideal for short lived tasks
            AtomicInteger submitTaskCount = new AtomicInteger(0); //to keep track of submitted tasks

            CompletionService<T> service = new ExecutorCompletionService<>(executor);
            try {
                iterable.forEach(u -> {                        //note that iterable.size() must not be really large as cached thread pool is unbounded
                    //we typically restrict this size bound when we accept the request itself.
                    service.submit(() -> {
                        log.info("Submitting task: splitJoin f({}) on {}", u, Thread.currentThread().getName());
                        return mapper.apply(u);
                    });     //user specified mapper is invoked here to create a task and submitted
                    submitTaskCount.incrementAndGet();
                });
            } finally {
                executor.shutdown();                           // stop accepting any more tasks except for the ones that are submitted
            }
            List<T> results = new ArrayList<>();
            for (int i = 0; i < Math.min(submitTaskCount.get(), size); i++) { //if we didn't do min(size, submitted) & size > submitted, it would lead to an
                //infinite loop as take() blocks on an empty queue
                T t;
                try {
                    t = service.take().get();
                    log.info("Finished {}/{}: {} on {}", i, submitTaskCount.get(), t, Thread.currentThread().getName());

                } catch (ExecutionException ex) {
                    log.error("Received error during computation for result in Thread [{}] {}", Thread.currentThread().getId(), ex.getMessage());
                    throw ex;                                   //letting the application handle it
                }
                if (t != null) {
                    results.add(t);                             //collecting the out of order result
                }
            }
            return results.stream().collect(collector);         //applying user specified collector to the collection of intermediate results
        }
    }


    public static void main(String[] args) {
        MathService mathService = new RemoteMathService();
        ConcurrentWorkExecutor concurrentWorkExecutor = new OutOfOrderConcurrentWorkExecutor();
        WorkExecutor workExecutor = new WorkExecutor(mathService, concurrentWorkExecutor);

        List<Integer> input = Lists.newArrayList(10, 20, 7, 13, 34, -1, 14);
//        List<Integer> output = workExecutor.processExpensiveFunction(input, 3);
        List<Integer> output_ = workExecutor.processExpensiveFunctionElegant(input, 3);
//        log.info("Result: {}", output);
        log.info("Result: {}", output_);
    }

    class OutOfOrderConcurrentWorkExecutorTest {

        private OutOfOrderConcurrentWorkExecutor executor;

        @BeforeEach
        void setUp() {
            this.executor = new OutOfOrderConcurrentWorkExecutor();
        }

        @Test
        void testSplitJoinWaitsForAllResultsWhenSizeIsEqualToTheWorkSet() throws Exception {
            List<Integer> userIds = IntStream.range(1, 6).boxed().collect(Collectors.toList());
            Map<Integer, User> userIdUserMap = executor.splitJoin(
                    userIds.size(), userIds,
                    (id) -> new User(RandomStringUtils.randomAlphanumeric(2, 5), id),
                    Collectors.toMap(User::getId, Function.identity()));

            assertEquals(userIds.size(), userIdUserMap.size());
        }

        @Test
        void testSplitJoinWaitsForOnlyTheRequiredResultsWhenSizeIsLessThanWorkSet() throws Exception {
            List<Integer> userIds = IntStream.range(0, 6).boxed().collect(Collectors.toList());
            Map<Integer, User> userIdUserMap = executor.splitJoin(
                    userIds.size() / 2, userIds,
                    (id) -> new User(RandomStringUtils.randomAlphanumeric(2, 5), id),
                    Collectors.toMap(User::getId, Function.identity()));

            assertEquals(3, userIdUserMap.size());
        }

        @Test
        void testSplitJoinWaitsForAllResultsWhenSizeIsMoreThanTheWorkSet() throws Exception {
            List<Integer> userIds = IntStream.range(0, 4).boxed().collect(Collectors.toList());
            List<User> processedUsers = executor.splitJoin(
                    userIds.size() + 1, userIds,
                    (id) -> new User(RandomStringUtils.randomAlphanumeric(2, 5), id),
                    Collectors.toList());

            assertEquals(4, processedUsers.size());
        }

        @Test
        void testSplitJoinWaitsForAllResultsWhenIntermediateResultThrowsException() throws Exception {
            List<Integer> userIds = IntStream.range(0, 4).boxed().collect(Collectors.toList());
            Function<Integer, User> mapper = (id) -> {
                if (id == 2) {
                    throw new IllegalArgumentException("User 2 is blacklisted");
                }
                return new User(RandomStringUtils.randomAlphanumeric(2, 5), id);
            };
            try {
                executor.splitJoin(userIds.size(), userIds, mapper, Collectors.toList());

            } catch (RuntimeException ex) {
                assertTrue(ex.getMessage().contains("User 2 is blacklisted"));
                assertTrue(Throwables.getRootCause(ex) instanceof IllegalArgumentException);
            }
        }

        @Test
        void testSplitJoinReturnsSuccessfullyWhenOneResultThrowsExceptionButItIsNotRequired() throws Exception {
            List<Integer> userIds = IntStream.range(0, 4).boxed().collect(Collectors.toList());
            Function<Integer, User> mapper = (id) -> {
                if (id == 2) {
                    throw new IllegalArgumentException("User 2 is blacklisted");
                }
                System.out.println("Processing " + id);
                return new User(RandomStringUtils.randomAlphanumeric(2, 5), id);
            };
            try {
                executor.splitJoin(userIds.size() - 1, userIds, mapper, Collectors.toList());

            } catch (RuntimeException ex) {
                assertTrue(ex.getMessage().contains("User 2 is blacklisted"));
                assertTrue(Throwables.getRootCause(ex) instanceof IllegalArgumentException);
            }
        }

        private class User {

            private final String name;
            private final Integer id;

            public User(String name, Integer id) {
                this.name = name;
                this.id = id;
            }

            public String getName() {
                return name;
            }

            public Integer getId() {
                return id;
            }

            @Override
            public String toString() {
                return "name='" + name + '\'' + ", id=" + id + '}';
            }
        }
    }

}