
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class splitDel {

public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String s = br.readLine();

    StringTokenizer st = new StringTokenizer(s,(" [!,?."+"\\"+"_'@]+"));
    System.out.println(st.countTokens());

    while (st.hasMoreTokens())
        System.out.println(st.nextToken());
}
}
