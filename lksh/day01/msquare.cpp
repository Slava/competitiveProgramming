#include <cstdio>
#include <cstdlib>

const int N = 4;
int a[N * N], u[N * N], s[N], S[N], sum, A[N][N], cur;

bool go(int x, int y) {
	if (y == N) {
		if (S[x] != sum)return 0;
		x++; y = 0;
	}
	if (x == N) {
		for (int i = 0; i < N; i++)
			if (s[i] != sum)
				return 0;
		return 1;
	}
	for (int i = 0; i < N * N; i++) {
		if (u[i] || S[x] + a[i] > sum || s[y] + a[i] > sum)
			continue;
		S[x] += a[i]; s[y] += a[i]; u[i] = 1; A[x][y] = a[i];
		if (go(x, y + 1))return 1;
		S[x] -= a[i]; s[y] -= a[i]; u[i] = 0;
	}
	return 0;
}

int main() {
#ifndef imslavko
	freopen("msquare.in", "r", stdin);
	freopen("msquare.out", "w", stdout);
#endif
	for (int i = 0; i < N * N; i++)
		scanf("%d", a + i), sum += a[i];
	if (sum % N != 0) {
		printf("NO SOLUTION\n");
		return 0;
	}
	sum /= N;
	if (!go(0,0))
		printf("NO SOLUTION\n");
	else for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			printf("%3d%c", A[i][j], " \n"[j == N - 1]);
	return 0;
}
