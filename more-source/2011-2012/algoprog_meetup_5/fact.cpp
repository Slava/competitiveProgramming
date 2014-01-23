#include <cstdio>
#include <cstdlib>
#include <algorithm>

const int N = 1000001;
bool p[N];
int pr[N], prn, n, a[N];
int main() {
	freopen("fact.in", "r", stdin);
	freopen("fact.out", "w", stdout);
	pr[prn++] = 2;
	for (int i = 3; i < N; i += 2)
		if (!p[i]) {
			for (int j = i + i; j < N; j += i)
				p[j] = 1;
			pr[prn++] = i;
		}
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		int k = i;
		for (int j = 0; j < prn && k != 1; j++) {
			if (pr[j] * pr[j] > k) {
				j = std::lower_bound(pr, pr + prn, k) - pr;
		//		printf("for %d, %d became %d\n", i, k, j);
		//		fflush(stdout);
			}
			while (k % pr[j] == 0) {
				k /= pr[j];
				a[j]++;
			}
		}
	}
	int was = 0;
	for (int i = 0; i < prn; i++)
		if (a[i]) {
			if (was)
				printf("*");
			was = 1;
			printf("%d^%d", pr[i], a[i]);
		}
	puts("");
	return 0;
}
