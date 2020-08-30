import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class javaList {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in) );

        int N = Integer.parseInt((br.readLine().split(" "))[0]);

        ArrayList<Integer> A = new ArrayList<Integer>();
        StringTokenizer st = new StringTokenizer(br.readLine());
        while (st.hasMoreTokens()){
            A.add(Integer.parseInt(st.nextToken()));
        }
        String arr[];


        int Q = Integer.parseInt((br.readLine().split(" "))[0]);
        int a, b;
        boolean except  = false;


        for (int i = 0; i < Q; i++){
            switch(br.readLine()){
                case "Insert":
                    arr = br.readLine().split(" ");
                    a = Integer.parseInt(arr[0]);
                    b = Integer.parseInt(arr[1]);
                    A.add(a, b);
                    break;

                case "Delete":
                    arr = br.readLine().split(" ");
                    a = Integer.parseInt(arr[0]);
                    A.remove(a);
                    break;
            }
        }

           for (Integer c : A)
            System.out.print(c + " ");
    }
}
