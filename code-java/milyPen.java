/* IMPORTANT: Multiple classes and nested static classes are supported */
import java.io.*;
import java.util.*;

class milyPen {
    public static void main(String args[] ) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testcases = Integer.parseInt(br.readLine());
        int N, P, M;
        while(testcases-- > 0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            P = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            boolean H[] = new boolean[N + 1] ;
            boolean can = true;

            String A[] = br.readLine().split(" ");
            for (int i = 0; i < P; i++){
                int val = Integer.parseInt(A[i]);
                if (val <= N)
                H[val] = true;
            }

            A = br.readLine().split(" ");
            for (int i = 0; i < M; i++){
                int val = Integer.parseInt(A[i]);
                if (val <= N)
                    H[val] = true;
            }
            for (int i = 1; i <= N; i++){
                if (H[i] == false)
                    can = false;
            }
            System.out.println(can ? "They can" : "They can't");
        }

    }
}
