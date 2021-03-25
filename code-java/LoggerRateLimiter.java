package com.random.aman;

import java.util.HashMap;
import java.util.Map;

class LoggerRateLimiter {

    private final Map<String, Integer> nextMessageTimeStamp;
    private static final int UNIQUE_THRESHOLD_SECONDS = 10;

    /**
     * Initialize your data structure here.
     */
    public LoggerRateLimiter() {
        this.nextMessageTimeStamp = new HashMap<>();
    }

    /**
     * Returns true if the message should be printed in the given timestamp, otherwise returns false.
     * If this method returns false, the message will not be printed.
     * The timestamp is in seconds granularity.
     */
    public boolean shouldPrintMessage(int timestamp, String message) {
        Integer nextTimeStamp = nextMessageTimeStamp.get(message);
        nextMessageTimeStamp.putIfAbsent(message, timestamp + UNIQUE_THRESHOLD_SECONDS);
        if (nextTimeStamp == null) {
            return true;
        }
        if (timestamp >= nextTimeStamp) {
            nextMessageTimeStamp.put(message, timestamp + UNIQUE_THRESHOLD_SECONDS);
            return true;
        } else {
            return false;
        }
    }
}
