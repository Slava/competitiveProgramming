#include <cstdio>
#include <cstdlib>

typedef long long Int;

Int mod, A, B;

Int mult(Int a, Int b) {
	Int res = 0;
	while (b > 0) {
		if (b & 1LL)
			res = (res + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return res;
}

Int pow(Int a, Int b) {
	Int res = 1;
	while (b > 0) {
		if (b & 1LL)
			res = mult(res, a);
		a = mult(a, a);
		b >>= 1;
	}
	return res;
}

/*
 phi(p) = p - 1
 phi(ab) = phi(a) * phi(b)
 phi(p^a) = p^a - p^{a-1} = p * (1 - 1/p)
 n = p1^a1 * p2^a2 * ...
 phi(n) = n * (1 - 1/p1) * (1 - 1/p2) * ...
*/

Int phi(Int n) {
	Int res = n;
	for (Int i = 2; i <= n; i++)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			res -= res / i;
		}
	if (n > 1)
		res -= res / n;
	return res;
}

#ifdef WIN32
#define lld "%I64d"
#else
#define lld "%Ld"
#endif

int main() {
	scanf(lld lld lld, &A, &B, &mod);
//	printf(lld "\n", pow(A, B % phi(mod)));
	printf(lld "\n", pow(A, B));
	return 0;
}

