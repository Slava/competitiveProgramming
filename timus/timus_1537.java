import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	
	private static void solve() throws IOException {
		int n = nextInt(), p = nextInt();
		int[] a = new int[n + 20];
		
		a[2] = 1;
		for (int i = 3; i <= n; i++) {
			a[i] = a[i - 1];
			if (i % 2 == 0)
				a[i] += a[i / 2];
			a[i] %= p;
		}
		out.println(a[n] % p);
	}
	
	static BufferedReader in;
	static StringTokenizer tok = new StringTokenizer("");
	static PrintWriter out;
	
	public static void main(String[] args) throws IOException {
		//in = new BufferedReader(new FileReader("input.txt"));
		//out = new PrintWriter(new FileWriter("output.txt"));
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		
		Main.solve();
		out.close();
		in.close();
	}
	
	private static String nextToken() throws IOException {
		while (!tok.hasMoreTokens())
			tok = new StringTokenizer(in.readLine());
		return tok.nextToken();
	}

	private static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	private static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	
	private static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}
