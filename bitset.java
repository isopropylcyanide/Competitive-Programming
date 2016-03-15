import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Solution {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in) );

        String inp[] = br.readLine().split(" ");
        int N = Integer.parseInt(inp[0]);
        int M = Integer.parseInt(inp[1]);
        BitSet b1 = new BitSet(N);
        BitSet b2 = new BitSet(N);
        int a;

        for (int i = 0; i < M; i++){
            inp = br.readLine().split(" ");
            switch( inp[0]){
                case "AND":
                    a = Integer.parseInt(inp[1]);
                    if (a == 1)
                        b1.and(b2);
                    else
                        b2.and(b1);
                    break;

                case "OR":
                    a = Integer.parseInt(inp[1]);
                    if (a == 1)
                        b1.or(b2);
                    else
                        b2.or(b1);
                    break;

                case "FLIP":
                    a = Integer.parseInt(inp[1]);
                    if (a == 1)
                        b1.flip(Integer.parseInt(inp[2]));
                    else
                        b2.flip(Integer.parseInt(inp[2]));
                    break;

                case "XOR":
                    a = Integer.parseInt(inp[1]);
                    if (a == 1)
                        b1.xor(b2);
                    else
                        b2.xor(b1);
                    break;

                case "SET":
                    a = Integer.parseInt(inp[1]);
                    if (a == 1)
                        b1.set(Integer.parseInt(inp[2]));
                    else
                        b2.set(Integer.parseInt(inp[2]));
                    break;
            }
            System.out.println(b1.cardinality() + " " + b2.cardinality());
        }
    }
}
