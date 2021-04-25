import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;

public class PowerBase {
    static long T, Q, N;
    static int MAXM = 100005;
    static long ANS[] = new long[MAXM];

    static long findMinDiff(long N) {
        // Finds the minimum abs diff of N and a ^ b for some a, b > 1
        if (N < 4)
            return 4 - N;

        long minDiff = Long.MAX_VALUE;
        long minDiffVal = 1;
        long roundVal = -1;

        for (int i = 2; (i - 1) * (i - 1) <= N; i++) {
            double rVal = Math.round(Math.log(N) / Math.log(i));
            System.out.println(i + ": " + rVal);

            long curDiff = Math.abs(N - (long) (Math.pow(i, rVal)));
            if (curDiff < minDiff) {
                minDiff = curDiff;
                minDiffVal = i;
                roundVal = (long) rVal;
            }

            System.out.println(minDiffVal + " and " + minDiff + "\n");
        }
        long val = Math.abs(N - (long) (Math.pow(minDiffVal, roundVal)));
        return val;
    }

    public static void main(String[] args) throws IOException {
        findMinDiff(100);
        // System.out.println("done");

        // for (int i = 1; i <= 20; i++)
        //     System.out.print(" "+ANS[i]);

        Reader r = new Reader();
        T = r.nextLong();
        while (T-- > 0) {

            Q = r.nextLong();
            while (Q-- > 0) {
                N = r.nextLong();
                if (N < MAXM)
                    System.out.println(ANS[(int) N]);
                else
                    System.out.println(0);
            }
        }
    }

    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public Reader(String file_name) throws IOException {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String readLine() throws IOException {
            byte[] buf = new byte[64]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (neg)
                return -ret;
            return ret;
        }

        public long nextLong() throws IOException {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }

        public double nextDouble() throws IOException {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();

            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');

            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9')
                    ret += (c - '0') / (div *= 10);
            }

            if (neg)
                return -ret;
            return ret;
        }

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

        public void close() throws IOException {
            if (din == null)
                return;
            din.close();
        }
    }
}
