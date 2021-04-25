import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

class EqualChoc {
    static private int N;
    static private ArrayList<Integer> A;

    static void solve() {
        // Distribute equal chocolates to all in minimum moves
        int min = Collections.min(A), r = Integer.MAX_VALUE;
        for (int t = min - 4; t <= min; t++) {
            int s = 0;
            for (int i = 0; i < A.size(); i++) {
                int D = A.get(i) - t;
                s += D / 5;
                D %= 5;
                s += D / 2;
                D %= 2;
                s += D;
            }
            r = Math.min(r, s);
        }
        System.out.println(r);
    }


    public static void main(String[] args) {
        int testcases, N;
        Scanner s = new Scanner(System.in);
        testcases = s.nextInt();
        A = new ArrayList<Integer>();

        while (testcases-- > 0) {
            A.clear();
            N = s.nextInt();
            for (int i = 0; i < N; i++)
                A.add(s.nextInt());
            solve();
        }
    }
}
