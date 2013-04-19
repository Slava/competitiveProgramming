#include <cstdio>
#include <cstdlib>
#include <vector>
#define bit(x,y) (((x)>>(y))&1)

using namespace std;

const int PR = 1 << 17;
typedef unsigned int Int;
Int n, m, pr, MOD = 1000000000;
Int d[2][PR], now, prv, i, j, k, Pr;
Int ans;

bool good(int x, int y, int z, int a) {
	return !(x == y && y == z && z == a);
}
int main() {
#ifndef imslavko
	freopen("nice2.in", "r", stdin);
	freopen("nice2.out", "w", stdout);
#endif
	scanf("%u%u", &n, &m);
	if (n > m)
		n += m, m = n - m, n -= m;
	if (n == 1) {
		ans = 1;
		for (i = 0; i < m; ++i) {
			ans <<= 1; ans %= MOD;
		}
		printf("%u\n", ans);
		return 0;
	}
	pr = 1 << (n + 1);
	for (i = 0; i < pr; ++i)
		d[0][i] = 1;
	now = 1;
	for (i = 1; i < m; ++i)
		for (j = i == 1; j < n; ++j) {
			for (k = 0; k < pr; ++k) {
				Pr = k; Pr &= ~(1 << n); Pr <<= 1;
				d[now][k] = 0;
				if (!j)
					d[now][k] = d[prv][Pr] + d[prv][Pr ^ 1];
				else {
					if (good(Pr & 1, k & 1, bit(Pr, n), bit(k, n)))
						d[now][k] = d[prv][Pr];
					Pr |= 1;
					if (good(Pr & 1, k & 1, bit(Pr, n), bit(k, n)))
						d[now][k] = d[now][k] + d[prv][Pr];
				}
				while (d[now][k] >= MOD) d[now][k] -= MOD;
			}
			now ^= 1; prv ^= 1;
		}
	for (i = 0; i < pr; ++i) {
		ans += d[prv][i];
		while (ans >= MOD) ans -= MOD;
	}
	printf("%u", ans % MOD);
	return 0;
}
