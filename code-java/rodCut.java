import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.lang.Math;

class rodCut {

    static int minRodCut(int n){
        //Find number of special rods
         return (int) (Math.log(n) / Math.log(2));
    }


    public static void main(String args[] ) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        int testcases = Integer.parseInt(line);
        while (testcases-- > 0){
            int n = Integer.parseInt(br.readLine());
            System.out.println(minRodCut(n));
        }

    }
}
