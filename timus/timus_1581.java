import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	
	private static void solve() throws IOException {
		int n = nextInt(), current = nextInt(), number = 1;
		for (int i = 1; i < n; i++) {
			int newnumber = nextInt();
			if (newnumber == current)
				number++;
			else {
				out.print(number + " " + current + " ");
				number = 1;
				current = newnumber;
			}
		}
		if (number > 0)
			out.print(number + " " + current);
		out.println();
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
