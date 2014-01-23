#include <cstdio>
#include <cstdlib>
int bit(int x, int y) {
	x >>= y;
	return x%2;
}

const int N = 700;
int n, m, d[] = {0,0,0,1,1,0,-1,0,0,-1,1,1,-1,-1,1,-1,-1,1};
char s[N][N];
int a[N][N];

bool ok(int j, int m1, int m2, int m3) {
	int c0 = bit(m1,0)+bit(m1,1)+
		bit(m2,0)+bit(m2,1)+
		bit(m3,0)+bit(m3,1);
	int c1 = 
			bit(m1,0)+bit(m1,1)+bit(m1,2)+
			bit(m2,0)+bit(m2,1)+bit(m2,2)+
			bit(m3,0)+bit(m3,1)+bit(m3,2);
	int c2 = 
			bit(m1,3)+bit(m1,1)+bit(m1,2)+
			bit(m2,3)+bit(m2,1)+bit(m2,2)+
			bit(m3,3)+bit(m3,1)+bit(m3,2);
	int c3 = bit(m1,2)+bit(m1,3)+
		bit(m2,2)+bit(m2,3)+
		bit(m3,2)+bit(m3,3);
	return c0 == a[0][j] && c1 == a[1][j] && c2 == a[2][j] && c3 == a[3][j];
}

bool dp[1<<4][1<<4][600];
int from[1<<4][1<<4][600];

int main(int argv, char **argc) {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
		for (int j = 0; j < m; j++)
			a[i][j] = s[i][j] - '0';
	}
	for (int i = 0; i < (1<<4); i++) {
		for (int j = 0; j < (1<<4); j++)
			if (ok(0,0,i,j)) {
				dp[i][j][1] = 1;
			}
	}

	for (int i = 1; i < m; i++)
		for (int m1 = 0; m1 < (1<<4); m1++)
			for (int m2 = 0; m2 < (1<<4); m2++) if (dp[m1][m2][i])
				for (int m3 = 0; m3 < (1<<4); m3++)
					if (ok(i,m1,m2,m3)) {
						dp[m2][m3][i+1] = 1;
						from[m2][m3][i+1] = m1;
					}
	int ans = -1, prv = 0;
	for (int i = 0; i < (1<<4); i++)
		if (dp[i][0][m]) {
			ans = i;
		}
	if (ans == -1)return 0;

	for (int i = m; i > 0; i--) {
		for (int j = 0; j < 4; j++)
			if (bit(ans,j))printf("X");
			else printf(".");
		puts("");
		int t = ans;
		ans = from[ans][prv][i];
		prv = t;
	}

	return 0;
}

