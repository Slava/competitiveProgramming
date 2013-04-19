#include <cstdio>
#include <cstdlib>

int n, st[100100], m, x, a[100100], p;
int main() {
	scanf("%d", &n); p = n;
	for (int i = n - 1; i >= 0; i--)
		scanf("%d", a + i);
	for (int i = 1; i <= n; i++) {
		st[m++] = i;
		while (m && p && a[p - 1] == st[m - 1])
			--p, --m;
	}
	if (!p && !m) puts("Not a proof");
	else puts("Cheater");
	return 0;
}
