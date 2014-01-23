#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 18;
int dp[1<<N][N][3];
char fr[1<<N][N][3],
	 Fr[1<<N][N][3];
int n, a[N][3];

bool in(int i, int j, int k, int l) {
	int h1 = a[i][(j+1)%3], h2 = a[k][(l+1)%3],
		w1 = a[i][(j+2)%3], w2 = a[k][(l+2)%3];
	return min(h1,w1) <= min(h2,w2) &&
			max(h1,w1)<= max(h2,w2);
}

int main() {
	freopen("boxes.in", "r", stdin);
	freopen("boxes.out", "w", stdout);

	memset(fr, -1, sizeof fr);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &a[i][j]);
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			dp[1<<i][i][j] = a[i][j];

	for (int m = 1; m < (1 << n) - 1; m++)
		for (int i = 0; i < n; i++) if (m & (1 << i))
			for (int j = 0; j < 3; j++) if (dp[m][i][j])
				for (int k = 0; k < n; k++) if (!(m&(1<<k)))
					for (int l = 0; l < 3; l++)
						if (in(i,j,k,l)) {
							int tom = m | (1 << k);
							if (dp[tom][k][l] < dp[m][i][j] + a[k][l]) {
								dp[tom][k][l] = dp[m][i][j] + a[k][l];
								fr[tom][k][l] = i;
								Fr[tom][k][l] = j;
							}
						}

	int I, J, K, maxans = -1;
	for (int i = 0; i < (1<<n); i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < 3; k++)
				if (maxans < dp[i][j][k]) {
					maxans = dp[i][j][k];
					I = i; J = j; K = k;
				}
	
	printf("%d\n", maxans);
//	fprintf(stderr, "dbg = %d %d %d\n", I, J, K);
	int cnt = 0;
	for (int t = I; t > 0; t >>= 1)
		cnt += t & 1;

	printf("%d\n", cnt);
	do {
		printf("%d %d %d %d\n", J + 1, max(a[J][(K+1)%3], a[J][(K+2)%3]),
									   min(a[J][(K+1)%3], a[J][(K+2)%3]),
									   a[J][K]);
//		printf("<<<< %d %d %d  %d\n", I, J, K, fr[I][J][K]);
		if (fr[I][J][K] == -1)break;
		int toJ = fr[I][J][K], toI = I - (1<<J), toK = Fr[I][J][K];
		I = toI; J = toJ; K = toK;;
	} while (true);
	return 0;
}
