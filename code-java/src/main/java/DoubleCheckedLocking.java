import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

class Singleton {

    //    private static Singleton instance;
    private static Singleton onlyInstance = new Singleton();

    private static volatile Singleton instance;

    private Singleton() {
    }

    public static Singleton getFastestInstance() {
        return onlyInstance;
    }

    public static Singleton getInstance() {
        if (instance == null) {
            synchronized (Singleton.class) {
                if (instance == null) {
                    instance = new Singleton();
                }
            }
        }
        return instance;
    }

    public static synchronized Singleton getSlowInstance() {
        if (instance == null) {
            instance = new Singleton();
        }
        return instance;
    }
}

class MyInt {
    private int count;

    MyInt() {
        this.count = 0;
    }

    public void increment() {
        synchronized (MyInt.class) {
            this.count += 1;
        }
    }

    public int get() {
        synchronized (MyInt.class) {
            return this.count;
        }
    }
}

public class Salu {

    public static void main(String[] args) throws InterruptedException {
        int maxWorkers = 100;
        final MyInt counter = new MyInt();
        System.out.println("Processors: " + Runtime.getRuntime().availableProcessors());

        CountDownLatch latch = new CountDownLatch(maxWorkers);
        ExecutorService service = Executors.newFixedThreadPool(maxWorkers);

        System.out.println("Starting submission");
        for (int i = 0; i < maxWorkers; i++) {
            service.submit(() -> {
                Singleton a = Singleton.getInstance();
                System.out.println("Runnable : " + a.hashCode() + " in thread: " + Thread.currentThread().getId());
                counter.increment();
                latch.countDown();
            });
        }
        service.shutdown();
        latch.await();
        System.out.println("Work done: " + counter.get());
        Thread.sleep(15000000);
    }
}
