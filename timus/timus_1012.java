import java.math.*;
import java.io.*;
import java.util.*;

public class bigKnum {
  
    public static void main(String args[]){
        Scanner in= new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
        int n=in.nextInt();
        int k=in.nextInt();
        
        BigInteger f1,f2,f3;
        f1=BigInteger.valueOf(k-1);
        f2=f1.multiply(BigInteger.valueOf(k));
        
        for(int i = 2; i < n; i++)
        {
            f3 = (f1.add(f2)).multiply(BigInteger.valueOf(k-1));
            f1 = f2;
            f2 = f3;
            
        }
       	out.println(f2); 
		out.flush();
    }
    
}
