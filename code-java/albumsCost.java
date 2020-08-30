/* IMPORTANT: Multiple classes and nested static classes are supported */

//imports for BufferedReader
import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.util.*;

class albumsCost {

    static int[] A;
    static int N, L, R, K, Q;

    public static void main(String args[] ) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        A = new int[N];
        int [][]B = new int[N][101];

        String s[] = br.readLine().split(" ");
        for (int i = 0; i < N; i++){
            A[i] = Integer.parseInt(s[i]);
            for (int j = 1; j <= 100; j++){
                B[i][j] = A[i] % j == 0 ? 1 : 0;
            }
        }
        for (int j = 1; j <= 100; j++)
            for (int i = 1; i < N; i++)
                B[i][j] += B[i -1][j];

        // for (int i = 0; i < N; i++){
        //     System.out.println("\n" + A[i]);
        //     for (int j = 1; j <= 100; j++)
        //         System.out.print(B[i][j] + " ");
        // }


        Q = Integer.parseInt(br.readLine());
        while (Q-- > 0){
            s = br.readLine().split(" ");
            L = Integer.parseInt(s[0]) -1;
            R = Integer.parseInt(s[1]) -1;
            K = Integer.parseInt(s[2]);

            int ans = 0;
            if (L == 0)
                ans = B[R][K];
            else
                ans = B[R][K] - B[L -1][K];

            System.out.println(ans);
        }


    }
}
