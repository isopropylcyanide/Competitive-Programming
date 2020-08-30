/* IMPORTANT: Multiple classes and nested static classes are supported */

//imports for BufferedReader
import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.util.*;

class palindTime {

    public static int isPalindrome(String s){
        // returns true if a string is palindromic
        int n = s.length();
        for (int i = 0; i < n/2; i++)
            if (s.charAt(i) != s.charAt(n - i -1))
                return 0;
        return 1;
    }

    public static char limit(int i, char prev){
        if (i == 0)
            return '2';
        else if (i == 1)
            return (prev == '2') ? '3' : '9';
        else if (i == 2)
            return '5';
        else return '9';
    }

    public static int f(int i, int tight, String t, int N, String s, boolean excl){
        // System.out.println("i: " + i + " tight: " + tight + " : " + t);
        int ans = 0;
        if (i == N){
            ans = isPalindrome(t);
            return ans;
        }

        if (tight == 0){
            // strictly less than
            for (char c = '0'; c <= limit(i, t.charAt(i -1)); c++)
                ans += f(i + 1, 0, t + c, N, s, excl);
        }
        else{
            char lim = s.charAt(i);
            if (i == 3 && excl)
                lim = (char)((int)lim -1);

            for (char c = '0'; c <= lim; c++){
                if (c == lim)
                    ans += f(i + 1, 1, t + c, N, s, excl);
                else
                    ans += f(i + 1, 0, t + c, N, s, excl);
            }
        }
        return ans;
    }

    public static void main(String args[] ) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0){
            String a[] = br.readLine().split(" ");
            String start = a[0], end = a[1];
            int numPalin = 0;

            int r = f(0, 1, "", 4, end, false);
            // System.out.println("\n R: " + r);
            int l = f(0, 1, "", 4, start, true);
            // System.out.println("\n L: " + l);
            System.out.println(r - l);
        }


    }
}
