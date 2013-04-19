import java.io.*;
import java.lang.*;
import java.math.*;
import java.util.*;

public class Main {
	final int mod = 1000000007;
	final int inf = 1000000000;
	int[][] min, num;
	
	public void solve() throws IOException {
		char[] s, t;
		s = nextToken().toCharArray();
		t = nextToken().toCharArray();

		min = new int[s.length + 1][t.length + 1];
		num = new int[s.length + 1][t.length + 1];
		
		for (int i = 0; i < min.length; i++)
			for (int j = 0; j < min[i].length; j++)
				min[i][j] = inf;
		
		min[0][0] = 0;
		num[0][0] = 1;
		
		for (int i = 0; i < min.length; i++)
			for (int j = 0; j < min[i].length; j++) {
				if (i == 0 && j == 0)
					continue;
				if (i > 0 && j > 0 && s[i - 1] == t[j - 1]) {
					if (min[i - 1][j - 1] + 1 < min[i][j]) {
						min[i][j] = min[i - 1][j - 1] + 1;
						num[i][j] = 0;
					}
					if (min[i - 1][j - 1] + 1 == min[i][j])
						num[i][j] = (num[i][j] + num[i - 1][j - 1]) % mod;
				}
				else {
					if (i > 0 && min[i - 1][j] + 1 < min[i][j]) {
						min[i][j] = min[i - 1][j] + 1;
						num[i][j] = 0;
					}
					if (i > 0 && min[i - 1][j] + 1 == min[i][j])
						num[i][j] = (num[i][j] + num[i - 1][j]) % mod;
				
					if (j > 0 && min[i][j - 1] + 1 < min[i][j]) {
						min[i][j] = min[i][j - 1] + 1;
						num[i][j] = 0;
					}
					if (j > 0 && min[i][j - 1] + 1 == min[i][j])
						num[i][j] = (num[i][j] + num[i][j - 1]) % mod;
				}
			}
		out.println(num[s.length][t.length]);
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
