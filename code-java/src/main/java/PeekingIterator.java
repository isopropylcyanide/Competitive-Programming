import java.util.Arrays;
import java.util.Iterator;

public class PeekingIterator implements Iterator<Integer> {

    private Integer peekedValue;
    private final Iterator<Integer> iterator;

    public PeekingIterator(Iterator<Integer> iterator) {
        // initialize any member here.
        this.iterator = iterator;
        if (this.iterator.hasNext()) {
            peekedValue = iterator.next();
        } else {
            peekedValue = null;
        }
    }

    // Returns the next element in the iteration without advancing the iterator.
    public Integer peek() {
        return peekedValue;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    @Override
    public Integer next() {
        Integer cachedNext = peekedValue;
        peekedValue = iterator.hasNext() ? iterator.next() : null;
        return cachedNext;
    }

    @Override
    public boolean hasNext() {
        return peekedValue != null;
    }

    public static void main(String[] args) {
        PeekingIterator iterator = new PeekingIterator(Arrays.asList(1, 2, 3).iterator());
        System.out.println(iterator.peek());

        iterator.next();
        System.out.println(iterator.peek());
    }
}


