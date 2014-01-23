#include <cstdio>
#include <cstdlib>

int n, k, mod;
typedef long long Int;

int fact(int n) {
	long long res = 1;
	for (int i = 2; i <= n; i++) {
		res *= i;
		res %= mod;
	}
	return int(res % mod);
}


int pow(Int a, Int b) {
	Int res = 1;
	while (b > 0) {
		if (b & 1LL)
			res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return (int)res;
}


int divmod(int n, int k) {
	Int res = (pow(k, mod - 2) * 1LL * n) % mod;
	return (int)res;
}

int main() {
	scanf("%d%d%d", &n, &k, &mod);
	
	if (k > n) {
		puts("0");
		return 0;
	}

	int nf = fact(n), kf = fact(k), nkf = fact(n - k);
//	fprintf(stderr, "facts: %d %d %d\n", nf, kf, nkf);
	printf("%d\n", divmod(nf, (kf * 1LL * nkf * 1LL) % mod));

	return 0;
}

