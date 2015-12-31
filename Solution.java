import java.io.*;
import java.util.*;
import java.math.BigInteger;

//JAVA Fast I/O 
//JAVA LCS and LCS Print Solutions

class Solution{

    static int binarySearch(int value, int low, int high, int [] arr){

        if (low > high)
            return -1;
        
        int mid = (low + high)/2;

        if (value == arr[mid])
            return mid;

        else if (value > arr[mid])
            return binarySearch(value, mid + 1, high, arr);

        else
            return binarySearch(value, low, mid -1 , arr);

    }

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        int value = s.nextInt();
        int size = s.nextInt();

        int arr[] = new int[size];

        for (int i = 0; i < size; i++){
            String token = s.next();
            arr[i] = Integer.parseInt(token);
        }

        Arrays.sort(arr);
        System.out.println(binarySearch(value,0,size - 1, arr));

    }
}