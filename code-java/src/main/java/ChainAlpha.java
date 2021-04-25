/* IMPORTANT: Multiple classes and nested static classes are supported */

//imports for BufferedReader

import java.io.BufferedReader;
import java.io.InputStreamReader;

class ChainAlpha {

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            String s = br.readLine();
            char nextChar = 'a';
            int pos = -1;
            int len = 0, i = 0;
            int flag = 0;

            while (nextChar != '{') {
                if (s.charAt(i) == nextChar) {
                    if (pos == -1)
                        pos = i;
                    else {
                        len += (i - pos);
                        pos = i;
                    }
                    nextChar++;
                }
                i += 1;
            }

            System.out.println(len);
        }
    }
}
