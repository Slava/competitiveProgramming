#include <cstdio>
#include <cstdlib>
#include <cstring>

int n, a[20], u[1000], g[1000];
int main() {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);

	for (int i = 1; i < 1000; i++) {
		memset(u, 0, sizeof u);
		u[g[i-1]] = 1;
		for (int j = 1; j < i; j++)
			u[g[j]^g[i-j-1]] = 1;
		if (i >= 2)
			u[g[i-2]] = 1;
		for (int j = 1; j < i - 1; j++)
			u[g[j]^g[i-j-2]] = 1;
		while (u[g[i]])
			g[i]++;
	}
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		sum ^= g[a[i]];
	}

	puts(sum ? "First wins." : "Second wins.");

	return 0;
}
