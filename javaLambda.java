import java.io.*;
import java.util.*;

interface performOperation{
    int check(int a);
}
class Maths{
   public static int checker(performOperation p ,int num){
       return p.check(num);
   }

    performOperation checkEvenOdd(){
        performOperation p = new performOperation(){
            public int check(int a){
                if (a % 2 == 0)
                    return 0;
                return 1;
            }
        };
        return p;
    }

    performOperation checkPrime(){
        performOperation p = new performOperation(){
            public int check(int a){
                if (a % 2 == 0)
                    return a == 2 ? 0 : -1;
                for (int i = 3; i <= a / 2; i += 2){
                    if (a % i == 0)
                        return -1;
                }
                return 0;
            }
        };
        return p;
    }

    performOperation checkPalindrome(){
        performOperation p = new performOperation(){
            public int check(int a){
                StringBuilder sb = new StringBuilder("" + a);
                String rev = sb.reverse().toString();

                if (rev.equals("" + a))
                    return 0;
                return -1;
            }
        };
        return p;
    }
}


class javaLambda {

    public static void main(String[] args)throws IOException {
        Maths ob = new Maths();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T=Integer.parseInt(br.readLine());
        performOperation op;
        int ret =0;
        String ans=null;
        while(T-->0){
            String s=br.readLine().trim();
            StringTokenizer st=new StringTokenizer(s);
            int ch=Integer.parseInt(st.nextToken());
            int num=Integer.parseInt(st.nextToken());
            if(ch==1){
                op = ob.checkEvenOdd();
                ret = Maths.checker(op,num);
                ans = (ret == 0)?"EVEN":"ODD";
            }
            else if(ch==2){
                op = ob.checkPrime();
                ret = Maths.checker(op,num);
                ans = (ret == 0)?"PRIME":"COMPOSITE";
            }
            else if(ch==3){
                op = ob.checkPalindrome();
                ret = Maths.checker(op,num);
              	ans = (ret == 0)?"PALINDROME":"NOT PALINDROME";

            }
            System.out.println(ans);
        }
    }

}
