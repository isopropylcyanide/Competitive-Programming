import java.io.*;
import java.util.*;
  
public class Main
{
    public static void main (String [] args) throws IOException 
    {
         
        int sum = 0;
        Scanner input = new Scanner(System.in);

        int testcases = input.nextInt();
        while (testcases > 0){

            int N = input.nextInt();
            int[] array = new int[N];

            for(int member = 0; member < N ; member++){
                array[member] = input.nextInt();
                sum += array[member];       
            }
           
            boolean [] sol = new boolean [sum / 2 + 1];
            sol [0] = true;//empty array
             
            for (int i : array)
                for (int j = sum / 2; j >= i; j--)
                    if (sol [j - i]) 
                        sol [j] = true;
                          
            int half = sum / 2;
            for (; !sol [half]; half--);
            System.out.println (((sum - half) - half));
          
        testcases -=1 ;
        }
    }
}
