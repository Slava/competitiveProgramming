import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	
	private static void solve() throws IOException {
		int n = nextInt(), m = nextInt();
		out.println(n * m % 2 == 1 ? "[second]=:]" : "[:=[first]");
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
