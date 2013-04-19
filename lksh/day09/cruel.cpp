#include <cstdio>
#include <cstdlib>
#include <cstring>

#define first "Schtirlitz\n"
#define second "Mueller\n"

const int N = 5010;
int n, g[N], u[N];
int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		memset(u, 0, sizeof u);
		u[g[i - 1]] = 1;
		for (int j = 1; j < i - 1; j++)
			u[g[j] ^ g[i - j - 1]] = 1;
		while (u[g[i]])
			g[i]++;
	}
	if (g[n]) {
		printf(first);
		if (!g[n - 1])
			printf("1\n");
		for (int i = 1; i < n - 1; i++)
			if (!(g[i] ^ g[n - i - 1]))
				printf("%d\n", i + 1);
		if (!g[n - 1])
			printf("%d\n", n);
	}
	else printf(second);
	return 0;
}
