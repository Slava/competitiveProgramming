import java.io.*;
import java.lang.*;
import java.math.*;
import java.util.*;

public class Main {
	public void solve() throws IOException {
		int[] a = new int[100003];
		int n = 3;
		String s;
		
		while (true) {
			if (!in.ready() && !tok.hasMoreElements())
				break;
			s = nextToken();
			int currentLength = 0;
			for (int i = 0; i < s.length(); i++)
				if ((s.charAt(i) >= 'A' && s.charAt(i) <= 'Z') || (s.charAt(i) >= 'a' && s.charAt(i) <= 'z'))
					currentLength++;
				else {
					if (currentLength > 0)
						a[n++] = currentLength;
					currentLength = 0;
				}
			if (currentLength > 0)
				a[n++] = currentLength;
		}
		
		int[] dp = new int[n];
		for (int i = 3; i < dp.length; i++)
			dp[i] = a[i] + Math.max(dp[i - 2], dp[i - 3]);
		
		out.println(Math.max(dp[n - 1], dp[n - 2]));
	}
	
	public void run() throws IOException {
		tok = new StringTokenizer("");
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		in.close();
		out.close();
	}
	
	public static void main(String[] args) throws IOException {
		new Main().run();
	}
	
	String nextToken() throws IOException {
		while (!tok.hasMoreTokens())
			tok = new StringTokenizer(in.readLine());
		return tok.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
	
	BufferedReader in;
	StringTokenizer tok;
	PrintWriter out;
}
