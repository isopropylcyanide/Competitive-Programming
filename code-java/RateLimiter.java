package com.atlassian.coding.ratelimiter;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.UUID;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicLong;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

public class Driver {

    public static void main(String[] args) {
        RateLimiter rateLimiter = RateLimiterFactory.withTokenBucket("atlassian-3p", 10);
    }

    public static class RateLimiterFactory {

        public static RateLimiter withTokenBucket(String customerId, int maxRequests) {
            return new RateLimiter.TokenBucketRateLimiter(maxRequests, customerId);
        }

    }

    public abstract static class RateLimiter {

        protected final int maxRequestsPerSec;
        private final String customerId;
        private final String rateLimiterId;

        protected RateLimiter(int maxRequestsPerSec, String customerId) {
            this.maxRequestsPerSec = maxRequestsPerSec;
            this.customerId = customerId;
            this.rateLimiterId = UUID.randomUUID().toString();
        }

        /**
         * Return true if request can get through
         *
         * @return false, otherwise
         */
        public abstract boolean allow();

        /**
         * Return true if a given number of requests can get through
         *
         * @return false, otherwise
         */
        public abstract boolean allow(int requests);

        public String getRateLimiterId() {
            return this.rateLimiterId;
        }

        public String getCustomerId() {
            return this.customerId;
        }

        abstract public long getLastAccessTime();

        public static class TokenBucketRateLimiter extends RateLimiter {

            private int tokens;
            private long lastRequestTime;

            public TokenBucketRateLimiter(int maxRequestsPerSec, String customerId) {
                super(maxRequestsPerSec, customerId);
                this.tokens = maxRequestsPerSec;
                this.lastRequestTime = getCurrentSystemTime();
            }

            @Override
            public boolean allow() {
                refillTokensInThePeriod();
                synchronized (this) {
                    if (tokens <= 0) {
                        return false;
                    }
                    tokens = tokens - 1;
                    return true;
                }
            }

            @Override
            public boolean allow(int requests) {
                refillTokensInThePeriod();
                synchronized (this) {
                    if (tokens <= requests) {
                        return false;
                    }
                    tokens = tokens - requests;
                }
                return true;
            }

            @Override
            public long getLastAccessTime() {
                synchronized (this) {
                    return this.lastRequestTime;
                }
            }

            /**
             * Refresh tokens that may have accrued due to inactivity of
             * requests in the rate limiter window.
             */
            private void refillTokensInThePeriod() {
                long currentTime = getCurrentSystemTime();
                double differentialTime = (currentTime - lastRequestTime) / 1_000.0;
                int additionalTokens = (int) differentialTime * maxRequestsPerSec;
                System.out.println("Additional: " + additionalTokens);

                synchronized (this) {
                    tokens = Math.min(tokens + additionalTokens, maxRequestsPerSec);
                }
                lastRequestTime = currentTime;
            }

            private long getCurrentSystemTime() {
                return System.currentTimeMillis();
            }
        }
    }

    static class TokenBucketRateLimiterTest {

        private RateLimiter rateLimiter;

        @BeforeEach
        void setUp() {
        }

        @Test
        void testAllowWhenYouHaveSufficientTokens() {
            rateLimiter = new RateLimiter.TokenBucketRateLimiter(3, "C1");
            assertTrue(rateLimiter.allow());
            assertTrue(rateLimiter.allow());
            assertTrue(rateLimiter.allow());
            assertFalse(rateLimiter.allow());
        }

        @Test
        void testAllowWhenYouHaveSufficientTokensWithDelay() throws InterruptedException {
            rateLimiter = new RateLimiter.TokenBucketRateLimiter(3, "C1");
            assertTrue(rateLimiter.allow());
            assertTrue(rateLimiter.allow());
            assertTrue(rateLimiter.allow());
            TimeUnit.SECONDS.sleep(1);

            assertTrue(rateLimiter.allow());
        }

        @Test
        void testRateLimiterAcrossSingleThread() throws InterruptedException {
            rateLimiter = new RateLimiter.TokenBucketRateLimiter(3, "C1");
            CountDownLatch latch = new CountDownLatch(1);
            AtomicLong failed = new AtomicLong(0);

            new Thread(() -> {
                if (!rateLimiter.allow()) {
                    failed.incrementAndGet();
                }
                if (!rateLimiter.allow()) {
                    failed.incrementAndGet();
                }
                if (!rateLimiter.allow()) {
                    failed.incrementAndGet();
                }
                latch.countDown();
            }).start();
            //
            boolean await = latch.await(3, TimeUnit.SECONDS);
            assertEquals(0, failed.get());
        }

        @Test
        void testRateLimiterAcrossSingleThreadFailsWhenTokensDoNotExist() throws InterruptedException {
            rateLimiter = new RateLimiter.TokenBucketRateLimiter(1, "C1");
            CountDownLatch latch = new CountDownLatch(1);
            AtomicLong failed = new AtomicLong(0);

            new Thread(() -> {
                if (!rateLimiter.allow()) {
                    failed.incrementAndGet();
                }
                if (!rateLimiter.allow()) {
                    failed.incrementAndGet();
                }
                latch.countDown();
            }).start();
            //
            boolean await = latch.await(3, TimeUnit.SECONDS);
            assertEquals(1, failed.get());
        }

        @Test
        void testRateLimiterAcrossMultipleThreads() throws InterruptedException {
            rateLimiter = new RateLimiter.TokenBucketRateLimiter(3, "C1");
            CountDownLatch latch = new CountDownLatch(2);
            AtomicLong failed = new AtomicLong(0);

            new Thread(() -> {
                if (!rateLimiter.allow()) {
                    failed.incrementAndGet();
                }
                if (!rateLimiter.allow()) {
                    failed.incrementAndGet();
                }
                latch.countDown();
            }).start();

            new Thread(() -> {
                if (!rateLimiter.allow()) {
                    failed.incrementAndGet();
                }
                if (!rateLimiter.allow()) {
                    failed.incrementAndGet();
                }
                latch.countDown();
            }).start();
            //
            boolean await = latch.await(3, TimeUnit.SECONDS);
            assertEquals(1, failed.get());
        }
    }
}
