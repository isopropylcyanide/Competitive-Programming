
import java.util.*;
import java.lang.*;
import java.io.*;

class prodSquare{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int [] A = new int[N];
        for (int i = 0; i < N; i++)
            A[i] = Integer.parseInt(br.readLine());

        float total = N * (N - 1);
        int count = 0, number = 0;
        HashMap<Integer, Integer> m = new HashMap<Integer,Integer>();

        for(int i = 0; i < N; i++){
            int numC = A[i];
            if (m.containsKey(numC)){
                count += m.get(numC);
                continue;
            }
            int subNum = 0;
            for (int j = 0; j < N; j++){
                if (j != i){
                    number = numC * A[j];
                    if(Math.round(Math.sqrt(number))==Math.sqrt(number)){
                        count += 1;
                        subNum += 1;
                    }
                }
            }
            m.put(numC, subNum);
        }

        System.out.println(String.format("%6f",count/total));
    }
}
