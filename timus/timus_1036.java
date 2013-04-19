import java.io.*;
import java.math.*;
import java.util.*;

public class timus_1036{
	static int[][] u = new int[60][1010];
	static BigInteger[][] d = new BigInteger[60][1010];
	public static void r (int n, int k){
		if (u[n][k] != 0)
			return;
		u[n][k] = 1;
		if (n == 0) if (k != 0) d[n][k] = BigInteger.ZERO;
		else d[n][k] = BigInteger.ONE;
		else
		for (int i = 0; i < 10; i++)
			if (k - i >= 0){
				r(n - 1, k - i);
				d[n][k] = d[n][k].add(d[n - 1][k - i]);
			}
	}
	public static void main (String[] argc){
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int n = in.nextInt(), k = in.nextInt();
		if (k % 2 == 1){out.println("0");out.flush();System.exit(0);}
		for (int i = 0; i < 60; i++)for (int j = 0; j < 1010; j++)
			d[i][j] = BigInteger.ZERO;
		r(n, k / 2);
		BigInteger a = d[n][k / 2]; a = a.multiply(a);
		out.println(a);
		out.flush();
	}
}

