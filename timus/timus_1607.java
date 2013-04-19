import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	
	private static void solve() throws IOException {
		int a = nextInt(), b = nextInt(), c = nextInt(), d = nextInt();
		for (int i = 0; ; i ^= 1) {
			if (a >= c) {
				out.printf("%d\n", a);
				return;
			}
			if ((i & 1) == 0) {
				if (a + b < c)
					a += b;
				else {
					out.printf("%d\n", c);
					return;
				}
			}
			else {
				if (c - d > a)
					c -= d;
				else {
					out.printf("%d\n", a);
					return;
				}
			}
		}
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
