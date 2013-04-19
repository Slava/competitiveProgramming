#include <cstdio>

int p[10] = {1}, a[200];
int n, m;

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d", p + i);
	for (int i = 1; i <= n; i++) {
		a[i] = 0;
		for (int j = 0; j <= m; j++)
			if (i - p[j] > 0)
				a[i] |= !a[i - p[j]];
		if (i % 2 == 0 && i > 10) {
			for (int j = 1, k = i / 2 + 1; j <= i / 2; j++, k++)
				if (a[j] != a[k])
					goto end;
			n %= i;
			if (!n)
				n = i;
			goto ans;
		}
		end:;
	}
ans:
	if (a[n])
		puts("FIRST PLAYER MUST WIN");
	else puts("SECOND PLAYER MUST WIN");
}

int main() {
	int t;
	for (scanf("%d", &t); t--; )
		solve();
	return 0;
}

