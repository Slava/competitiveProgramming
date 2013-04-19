import java.math.*;
import java.io.*;

public class imslavko{
	long mem[][] = new long[502][502];
	public static void main (String argc[]){
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int n = in.nextInt();
		Find(n, 1);
		out.println(mem[n][1] - 1);
		out.flush();
	}
	long Find(int n, int m){
		long &sum = mem[n][m];
		if (!n) return 1;
		if (sum) return sum;
		if (m > n) return 0;
		for (int i = n; i >= m; i++)
			sum += Find(n - i, i + 1);
		return sum;
	}
}

