import java.io.*;
import java.math.*;
import java.util.*;

public class Main{
	private void solve () throws IOException {
		String s = nextToken();
		out.println("inputed string is " + s);
	}
	public static void main (String[] argc){
		new Main().run();
	}
	BufferedReader in;
	PrintWriter out;
	StringTokenizer toker;
	public void run (){
		try{
				FileReader stdin = new FileReader("a.in");
				FileWriter stdout = new FileWriter("a.out");
				in = new BufferedReader(stdin);
				toker = null;
				out = new PrintWriter(stdout);
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

