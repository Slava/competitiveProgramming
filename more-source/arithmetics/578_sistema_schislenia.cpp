#include <cstdio>

int n, a[300], p;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &p);
	while (p > 0) {
		a[n] = p % 3;
		p /= 3; n++;
	}
	for (int i = 0; i < n - 1; i++)
		if (a[i] <= 0) {
			a[i] += 3;
			a[i + 1]--;
		}
	while (n > 1 && !a[n - 1])n--;
	for (int i = n - 1; i >= 0; i--)
		printf("%d", a[i]);
	return 0;
}
