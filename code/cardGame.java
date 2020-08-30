/* IMPORTANT: Multiple classes and nested static classes are supported */

import java.io.*;
import java.util.*;
import java.lang.*;

public class cardGame {
    public static void main(String args[] ) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testcases = Integer.parseInt(br.readLine());
        Scanner s = new Scanner(System.in);
        ArrayList<Integer> S, P;

        while (testcases != 0) {
            S = new ArrayList<Integer>();
            P = new ArrayList<Integer>();
            int N = Integer.parseInt(br.readLine());

            String []sA = br.readLine().split(" ");
            for (String  c : sA)
                S.add(Integer.parseInt(c));

            String []sB = br.readLine().split(" ");
            for (String c : sB)
                P.add(Integer.parseInt(c));

            String player = br.readLine();
            // Find parity of two permutations
            int pA = 0, pB = 0;
            for (int i = 1; i < N; i++){
                if (S.get(i) < S.get(i - 1))
                    pA += 1;
            }

            for (int i = 1; i < N; i++){
                if (P.get(i) < P.get(i - 1))
                    pB += 1;
            }

            if (Math.abs(pA % 2 - pB % 2) == 1)
                System.out.println(player);
            else
                System.out.println(player == "Devu" ? "Churu" : "Devu");

            testcases --;
        }

    }
}
