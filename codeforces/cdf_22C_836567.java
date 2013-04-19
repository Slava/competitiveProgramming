import java.io.*;
import java.math.*;
import java.util.*;

public class Main{
 	private void solve () throws IOException {
		long n = nextLong(), m = nextLong(), v = nextLong();
		if ((n - 2) * (n - 1) / 2 + 1 < m || m < n - 1) {
			out.println("-1");
			return;
		}
		long u = (v%n) + 1;
		out.println(v + " " + u);
		
		m--;
		for (int i = 1; i <= n && m > 0; i++)
			for (int j = i + 1; j <= n && m > 0; j++)
				if(i != u && j != u) {
					--m;
					out.println(i + " " + j);
				}
	}
	public static void main (String[] argc){
		new Main().run();
	}
	BufferedReader in;
	PrintWriter out;
	StringTokenizer toker;

	public void run (){
		try{
//				FileReader stdin = new FileReader("a.in");
//				FileWriter stdout = new FileWriter("a.out");
				in = new BufferedReader(new InputStreamReader(System.in));
				toker = null;
				out = new PrintWriter(System.out);
				solve();
				in.close();
				out.close();
		}
		catch (Exception e){
			System.exit(1);
		}
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
	String nextToken() throws IOException {
		while (toker == null || !toker.hasMoreTokens()){
			toker = new StringTokenizer(in.readLine());
		}
		return toker.nextToken();
	}
}





// lang: Java 6
// memory: 42300 KB
// author: imslavko
// submit_date: Nov 5, 2011 6:09:05 PM
// contest: 22
// link: /contest/22/submission/836567
// time: 170 ms
// verdict: Accepted
// problem: 22C - System Administrator
// ID: 836567
// downloaded by very stupid script
