import java.io.*;
import java.math.*;
import java.util.*;

public class a {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int n, m, w, h, k;
		n = in.nextInt();
		m = in.nextInt();
		w = in.nextInt();
		h = in.nextInt();
		k = min(in.nextInt(),100);

		if (h > n || w > n) {
			BigInteger res = BigInteger.ZERO;
			for (int i = 0; i <= k; i++)
				res = res.add(special(n,i).multiply(special(m,k-i)));
			out.println(res);
		} else if (max(h,w)+m <= n) {
			out.println(special(n,k));
		} else {
			if (h > w) {
				int t = h;
				h = w;
				w = t;
			}
			int Mid = n-w, Height = max(h+m,n);
			BigInteger[][][][] dp = new BigInteger[Height+1][w+1][m-n+w+1][2];

			for (int K=0;K<=k;K++)
				for (int G=Height;G>=0;G--)
					for (int L=0;L<=w;L++)
						for (int R=0;R<=m-n+w;R++) {
							int M = (k-K)-((w-L)+(m-n+w-R));
							M = Mid-M;
							BigInteger res = BigInteger.ZERO, t;
							int KK=(K-1)&1;
							
							if (M < 0 || M > Mid || K > Height-G || K > R+L+M)
								res = BigInteger.ZERO;
							else if (K == 0)
								res = BigInteger.ONE;
							else if (G != Height) {
								res = BigInteger.ZERO;
								if (G != Height)
									res = res.add(dp[G+1][L][R][K&1]);
								if (G < n && L > 0)
									res = res.add(dp[G+1][L-1][R][KK].multiply(BigInteger.valueOf(L)));
								if (G >= h && G < h+m && R > 0)
									res = res.add(dp[G+1][L][R-1][KK].multiply(BigInteger.valueOf(R)));
								if (M > 0)
									res = res.add(dp[G+1][L][R][KK].multiply(BigInteger.valueOf(M)));

							}

							dp[G][L][R][K&1] = res;
						}

			out.println(dp[0][w][m-n+w][k&1]);
		}

		out.println();
		out.close();
	}

	static int max(int a, int b) {
		return Math.max(a,b);
	}
	static int min(int a, int b) {
		return Math.min(a,b);
	}

	static BigInteger special(int n, int k) {
		BigInteger res = BigInteger.ONE;
		if (n < k) return BigInteger.ZERO;
		for (int i = 0; i < k; i++)
			res = res.multiply(BigInteger.valueOf(n-i));
		res = res.multiply(binomial(n,k));
		return res;
	}

	static BigInteger binomial(int n, int k) {
		BigInteger res = BigInteger.ONE;
		for (int i = 1; i <= n; i++) {
			if (i > k)
				res = res.multiply(BigInteger.valueOf(i));
		}

		for (int i = 1; i <= n-k; i++)
			res = res.divide(BigInteger.valueOf(i));
		return res;
	}
}
