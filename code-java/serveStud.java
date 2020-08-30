import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Student implements Comparable<Student>{
   private int token;
   private String fname;
   private double cgpa;
   public Student(int id, String fname, double cgpa) {
      super();
      this.token = id;
      this.fname = fname;
      this.cgpa = cgpa;
   }
   public int getToken() {
      return token;
   }
   public String getFname() {
      return fname;
   }
   public double getCgpa() {
      return cgpa;
   }

   public int compareTo(Student a){
       if(Double.compare(a.getCgpa(),this.getCgpa()) ==0){
           if(this.getFname().equals(a.getFname()))
               return (this.getToken() - a.getToken());
           else
               return this.getFname().compareTo(a.getFname());
       }
       else
           return Double.compare(a.getCgpa(),this.getCgpa());
   }

}



class serveStud {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in) );

        int N = Integer.parseInt((br.readLine().split(" "))[0]);
        TreeSet<Student> queue = new TreeSet<Student>();
        String a[];
        Double d;
        int t;
        String n;

        for (int i = 0; i < N; i++){
            a = br.readLine().split(" ");
            if (a[0].equals("ENTER")){
                n = a[1];
                d = Double.parseDouble(a[2]);
                t = Integer.parseInt(a[3]);
                Student s = new Student(t, n, d);
                queue.add(s);
            }

            else if (a[0].equals("SERVED")){
                if (queue.size() > 0)
                    queue.pollFirst();
                //else System.out.println("EMPTY");
            }
        }
        if (queue.size() == 0){
            System.out.println("EMPTY");
        }
        else{
            Iterator<Student> it = queue.iterator();
            while(it.hasNext()){
                System.out.println(it.next().getFname());
            }
        }
    }
}
