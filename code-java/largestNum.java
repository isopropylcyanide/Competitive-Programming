import java.lang.*;
import java.util.*;

class myComparator implements Comparator<String>{
    @Override
    public int compare(String a, String b){
        return -(a + b).compareTo(b + a);
    }
}

class largestNum {
	// DO NOT MODIFY THE LIST

	public String largestNumber(final List<Integer> a) {
        ArrayList<String> N = new ArrayList<>();
        for (int n : a)
            N.add(n + "");

        Collections.sort(N, new myComparator());

        StringBuilder sb = new StringBuilder();
        for (String str : N)
            sb.append(str);

        while(sb.charAt(0)=='0' && sb.length()>1)
            sb.deleteCharAt(0);

        return sb.toString();
	}

    public static void main(String[] args) {
        List<Integer> a = Arrays.asList(3, 30, 34, 5, 9);
        String c = new largestNum().largestNumber(a);
        System.out.println(c);
    }
}
