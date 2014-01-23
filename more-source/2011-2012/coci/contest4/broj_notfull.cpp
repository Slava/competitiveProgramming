#include <cstdio>
#include <cstdlib>

const int N = 1000000;
int lp[N+1], pr[N], prn;
int n, k;

int leastPrime(int x) {
	for (int i = 2; i <= n; i++)
		if (x % i == 0)
			return i;
	return x;
}

int main() {
	for (int i=2; i<=N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr[prn++] = i;
		}
		for (int j=0; j<prn && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
			lp[i * pr[j]] = pr[j];
	}

	scanf("%d%d", &k, &n);
	if (k == 1) {
		printf("%d\n", n);
		return 0;
	}
	k--;

	for (int i = 2; i <= N; i++)
		if (lp[i] >= n) {
			k--;
			if (i * n > 1000000000)
				break;
			if (!k) {
				printf("%d\n", i*n);
				return 0;
			}
		}
	for (int i = N+1; i*n <= 1000000000; i++)
		if (leastPrime(i) >= n){
			k--;
			if (!k) {
				printf("%d\n", i*n);
				return 0;
			}
		}

	puts("0");

	return 0;
}

