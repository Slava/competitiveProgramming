#include <cstdio>
#include <cstdlib>

const int N = 700;
int n, m, d[] = {0,0,0,1,1,0,-1,0,0,-1,1,1,-1,-1,1,-1,-1,1};
char s[N][N], S[N];
int a[N][N];

int check() {
	int ok = 1, more = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int sum = 0;
			for (int o = 0; o < 18; o += 2) {
				int di = i + d[o], dj = j + d[o+1];
				if (di >= 0 && di < n && dj >= 0 && dj < m)
					sum += a[di][dj] == 1;
			}
			if (sum > s[i][j] - '0')
				ok = 0;
			if (sum < s[i][j] - '0')
				more = 1;
		}
	if (!ok)return 0;
	if (more)return 2;
	return 1;
}

int main(int argv, char **argc) {
	freopen(argc[1], "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);
	freopen(argc[2], "r", stdin);
	for (int i = 0; i < n; i++) {
		scanf("%s", S);
		for (int j = 0; j < m; j++)
			a[i][j] = S[j] == 'X';
	}
	printf("%d\n", check());
	return 0;
}

