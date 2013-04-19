#include <cstdio>

const int N = 10010;
int a[N], n, p[N], s, need, sp, can[N], cans;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		s += a[i];
	}
	for (int i = 0; i < n; i++) {
		p[i] = 100 * a[i] / s;
		if ((100 * a[i]) % s != 0)
			can[i] = 1, cans++;
		sp += p[i];
	}
	need = 100 - sp;
	if (need > cans)
		printf("No solution");
	else
		for (int i = 0; i < n; i++) {
			if (can[i] && need)
				p[i]++, need--;
			printf("%d ", p[i]);
		}
	return 0;
}

