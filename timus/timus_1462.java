import java.io.*;
import java.util.*;
import java.math.*;

public class timus_1462{
	static BigInteger[] fib = new BigInteger[2000];
	public static void main (String[] argc){
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int n = in.nextInt();
		fib[0] = BigInteger.ZERO;
		fib[1] = BigInteger.ONE;
		for (int i = 2; i < 2000; i++)
			fib[i] = fib[i - 1].add(fib[i - 2]);
		out.println(f(n*2).divide(f(n)));
		out.flush();
	}
	static BigInteger f (int n){
		if (n < 2000) return fib[n];
		if (n % 2 == 0)
			return f(n / 2).multiply(f(n / 2 - 1).add(f(n / 2 + 1)));
		else{
			BigInteger t, p;
			t = f(n / 2); p = f(n / 2 + 1);
			return (t.multiply(t)).add(p.multiply(p));
		}
	}
}
