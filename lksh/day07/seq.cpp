#include <cstdio>
#include <cstdlib>
#include <map>

const int N = 51;
int t, n;
long long k, a[N];

int main() {
	a[-1] = a[0] = 1; a[1] = 2; a[2] = 4;
	for (int i = 3; i < N; i++)
		a[i] = a[i - 1] + a[i - 2] + a[i - 3];
	scanf("%d", &t);
	for (; t--; printf("\n")) {
		scanf("%d%lld", &n, &k);
		for (int i = 1; i <= n; i++) {
			if (k > a[n - i - 2] + a[n - i - 1]) {
				k -= a[n - i - 2] + a[n - i - 1];
				printf("1");
			}
			else if (i <= n - 1 && k > a[n - i - 2]) {
				k -= a[n - i - 2];
				printf("01"); i++;
			}
			else if (i <= n - 2) {
				printf("001"); i += 2;
			}
			else printf("0");
		}
	}
	return 0;
}
