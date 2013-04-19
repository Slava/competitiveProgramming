#include <cstdio>
#include <cstdlib>

int n, m, a[200];
int main() {
	scanf("%d", &n);
	if (!n) {
		printf("10\n");
		return 0;
	}
	if (n == 1) printf("1");
	while (n > 1) {
		bool ok = 0;
		for (int i = 9; i > 1; i--)
			if (n % i == 0) {
				a[m++] = i;
				n /= i; ok = 1;
				break;
			}
		if (!ok) {
			printf("-1\n");
			return 0;
		}
	}
	for (int i = m - 1; i >= 0; i--)
		printf("%d", a[i]);
	return 0;
}
