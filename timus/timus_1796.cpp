#include <cstdio>
#include <cstdlib>

int c[] = {10, 50, 100, 500, 1000, 5000};
int a[6], s, n, r, ans;
int main() {
	for (int i = 0; i < 6; i++) {
		scanf("%d", a + i);
		s += a[i] * c[i];
	}
	scanf("%d", &n);
	for (int i = 0; i < 6; i++)
		if (a[i] && s - c[i] > r)
			r = s - c[i];
	for (int i = r + 1; i <= s; i++)
		if (i % n == 0)
			ans++;
	printf("%d\n", ans);
	for (int i = r + 1; i <= s; i++)
		if (i % n == 0)
			printf("%d ", i / n);
	return 0;
}
