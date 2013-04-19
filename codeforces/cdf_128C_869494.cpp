#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef long long Int;

const Int Mod = 1000000007;

Int a[2000][2000];

int n, m, k;

Int mod(Int x) {
	if (x > Mod)
		x %= Mod;
	return x;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= max(n,m) + 1; i++)
		a[1][i] = 1;
	for (int i = 2; i <= k + 1; i++) {
		Int sum = 0;
		for (int j = i * 2 - 1; j <= max(n,m) + 1; j++) {
			a[i][j] = mod(a[i][j - 1] + sum + a[i - 1][j - 2]);
			sum = mod(sum + a[i - 1][j - 2]);
		}
	}

	printf("%lld\n", mod(a[k + 1][n] * a[k + 1][m]));
	return 0;
}




// lang: GNU C++
// memory: 32700 KB
// author: imslavko
// submit_date: Nov 15, 2011 11:57:10 AM
// contest: 128
// link: /contest/128/submission/869494
// time: 30 ms
// verdict: Accepted
// problem: 128C - Games with Rectangle
// ID: 869494
// downloaded by very stupid script
