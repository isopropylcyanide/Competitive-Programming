import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

class CompositeNum {
    static int maxN = 10005;
    static ArrayList<Integer> prime;

    public static void sieveOfEros() {
        prime = new ArrayList<Integer>(Collections.nCopies(maxN, 1));
        prime.set(0, 0);
        prime.set(1, 0);
        for (int i = 2; i < maxN; i++) {
            if (prime.get(i) == 1) {
                for (int j = i * i; j < maxN; j += i)
                    prime.set(j, 0);
            }
        }
    }

    public static void main(String[] args) {
        sieveOfEros();
        Scanner s = new Scanner(System.in);
        int N = s.nextInt();

        for (int i = 2; i <= N; i++)
            if (prime.get(i) == 0)
                System.out.print(i + " ");

    }
}
