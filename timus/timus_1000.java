import java.io.*;
import java.util.*;

public class imslavko{
	public static void main (String args[]){
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int a, b;
		a = in.nextInt();
		b = in.nextInt();
		a += b;
		out.println(a);
		out.flush();
	}
}

