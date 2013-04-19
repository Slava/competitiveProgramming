#include <cstdio>
#include <cstdlib>
#include <cstring>

const int N = 5100;
int g[N], a[N], A, B, C;
int main() {
	for (int i = 2; i < N; i++) {
		memset(a, 0, sizeof a);
		for (int j = 1; j < i; j++)
			if (j >= i - j)
				a[g[j]] = 1;
		while (a[g[i]])
			g[i]++;
	}
	scanf("%d%d%d", &A, &B, &C);
	if (g[A] ^ g[B] ^ g[C]) {
		printf("YES\n");
		for (int i = 1; i < A; i++)
			if (i >= A - i && !(g[i] ^ g[B] ^ g[C])) {
				printf("%d %d %d\n", i, B, C);
				return 0;
			}
		for (int i = 1; i < B; i++)
			if (i >= B - i && !(g[i] ^ g[A] ^ g[C])) {
				printf("%d %d %d\n", A, i, C);
				return 0;
			}
		for (int i = 1; i < C; i++)
			if (i >= C - i && !(g[i] ^ g[B] ^ g[A])) {
				printf("%d %d %d\n", A, B, i);
				return 0;
			}
	}
	else printf("NO\n");
	return 0;
}
