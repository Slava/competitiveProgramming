import java.io.*;
import java.lang.*;
import java.math.*;
import java.util.*;

public class Main {
	public void solve() throws IOException {
		int n = nextInt(), Ten = 10%n, One = 1%n;
		if (n == 1 || n == 2) {
			out.println(n);
			return;
		}
		boolean[][] dp = new boolean[30][n];
		dp[0][One] = dp[0][2%n] = true;
		for (int i = 0; i < 29; i++)
			for (int j = 0; j < n; j++) {
				int jj = j;
				if (jj >= n) jj %= n;
				int to = jj * Ten + One;
				if (to >= n) to %= n;
				dp[i + 1][to] |= dp[i][j];
				to++;
				if (to >= n) to %= n;
				dp[i + 1][to] |= dp[i][j];
			}
		
		int j = 0, k = 0;
		for (; j < 30; j++)
			if (dp[j][0])
				break;
		
		int[] ten = new int[j + 1];
		ten[0] = One;
		for (int i = 1; i < ten.length; i++)
			ten[i] = (ten[i - 1] * 10) % n;
		
		if (j == 30) {
			out.println("Impossible");
			return;
		}
		
		while (j > 0) {
			int to = k - ten[j];
			if (to >= n || to <= -n) to %= n;
			if (to < 0) to = (to + n) % n;
			if (dp[j - 1][to]) {
				k = to;
				out.print("1");
			}
			else {
				to = to - ten[j];
				if (to >= n || to <= -n) to %= n;
				if (to < 0) to = (to + n) % n;
				k = to;
				out.print("2");
			}
			j--;
		}
		out.println(k);
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
