import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Set;

public class PhoneDirectory {

    private final PriorityQueue<Integer> priorityQueue;
    private final Set<Integer> blockedNumbers;

    /**
     * Initialize your data structure here
     *
     * @param maxNumbers - The maximum numbers that can be stored in the phone directory.
     */
    public PhoneDirectory(int maxNumbers) {
        this.priorityQueue = new PriorityQueue<>(maxNumbers);
        this.blockedNumbers = new HashSet<>();
        for (int i = 0; i < maxNumbers; i++) {
            priorityQueue.add(i);
        }
    }

    /**
     * Provide a number which is not assigned to anyone.
     *
     * @return - Return an available number. Return -1 if none is available.
     */
    public int get() {
        if (!priorityQueue.isEmpty()) {
            Integer freeNumber = priorityQueue.poll();
            this.blockedNumbers.add(freeNumber);
            return freeNumber;
        }
        return -1;
    }

    /**
     * Check if a number is available or not.
     */
    public boolean check(int number) {
        return !blockedNumbers.contains(number);
    }

    /**
     * Recycle or release a number.
     */
    public void release(int number) {
        if (blockedNumbers.contains(number)) {
            blockedNumbers.remove(number);
            priorityQueue.add(number);
        }
    }

    public static void main(String[] args) {
        PhoneDirectory directory = new PhoneDirectory(3);
        System.out.println(directory.get());
        System.out.println(directory.get());
        System.out.println(directory.check(2));
        System.out.println(directory.get());
        System.out.println(directory.get());
        System.out.println(directory.check(2));
        directory.release(2);
        System.out.println(directory.check(2));
        System.out.println(directory.get());
    }
}
