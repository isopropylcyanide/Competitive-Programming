import java.io.*;
import java.util.*;
import java.math.BigInteger;

//JAVA Fast I/O 
//JAVA LCS and LCS Print Solutions

class InputReader {
 
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;
 
        public InputReader(InputStream stream) {
            this.stream = stream;
        }
 
        public int read() {
            if (numChars == -1)
                throw new InputMismatchException();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }
 
        public int readInt() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }
 
        public String readString() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }
 
        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
 
        public String next() {
            return readString();
        }
 
        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
        }
    }
 
class OutputWriter {
        private final PrintWriter writer;
 
        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }
 
        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }
 
        public void print(Object...objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0)
                    writer.print(' ');
                writer.print(objects[i]);
            }
        }
 
        public void printLine(Object...objects) {
            print(objects);
            writer.println();
        }
 
        public void close() {
            writer.close();
        }
 
        public void flush() {
            writer.flush();
        }
 
        }
 
class IOUtils {
 
        public static int[] readIntArray(InputReader in, int size) {
            int[] array = new int[size];
            for (int i = 0; i < size; i++)
                array[i] = in.readInt();
            return array;
        }
 
        }
 



class Main {

    static int arr[][];
    static void lcs(String s1, String s2) {
    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            if (s1.charAt(i - 1) == s2.charAt(j - 1))
                arr[i][j] = arr[i - 1][j - 1] + 1;
            else
                arr[i][j] = Math.max(arr[i - 1][j], arr[i][j - 1]);
        }
    }
}

static Set<String> lcs(String s1, String s2, int len1, int len2) {
    if (len1 == 0 || len2 == 0) {
        Set<String> set = new HashSet<String>();
        set.add("");
        return set;
    }
    if (s1.charAt(len1 - 1) == s2.charAt(len2 - 1)) {
        Set<String> set = lcs(s1, s2, len1 - 1, len2 - 1);
        Set<String> set1 = new HashSet<>();
        for (String temp : set) {
            temp = temp + s1.charAt(len1 - 1);
            set1.add(temp);
        }
        return set1;
    } else {
        Set<String> set = new HashSet<>();
        Set<String> set1 = new HashSet<>();
        if (arr[len1 - 1][len2] >= arr[len1][len2 - 1]) {
            set = lcs(s1, s2, len1 - 1, len2);
        }
        if (arr[len1][len2 - 1] >= arr[len1 - 1][len2]) {
            set1 = lcs(s1, s2, len1, len2 - 1);
        }
        for (String temp : set) {
            set1.add(temp);
        }
        return set1;

    }
}


public static void main(String[] args) {

    InputReader in  = new InputReader(System.in);
    OutputWriter out =   new OutputWriter(System.out);
    int n = in.readInt();
    int k = in.readInt();

    String s1 = in.readString();
    String s2 = in.readString();

    arr = new int[s1.length() + 1][s2.length() + 1];
    lcs(s1, s2);
    
    Set<String> a = lcs(s1, s2, s1.length(), s2.length()); 
    String [] all = a.toArray(new String[a.size()]);

    int ans = -1;
    if (all.length < k)
        out.printLine(-1);

    else{
        Arrays.sort(all);
        out.printLine(all[k-1]);
    }

   out.close();
}
}