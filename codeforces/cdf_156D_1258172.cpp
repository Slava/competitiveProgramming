#include <cstdio>

const int N = 100100;
int p[N], r[N], n, m, size;
long long k, sum, ans = 1;

long long binpow(long long a, int n) {
	long long res = 1;
	while (n > 0) {
		if (n & 1)
			res = (res * a) % k;
		a = (a * a) % k;
		n >>= 1;
	}
	return res;
}

int get(int x) {
	return x == p[x] ? x : (p[x] = get(p[x]));
}

int main() {
	scanf("%d%d%I64d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		p[i] = i, r[i] = 1;
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x = get(x);
		y = get(y);
		if (x == y) continue;
		p[y] = x;
		r[x] += r[y];
	}

        for (int i = 1; i <= n; i++)
       		if (p[i] == i)
       			size++, ans *= r[i], ans %= k, sum += r[i];

       	if (size < 2)
       		ans = 1;
       	else 
       		ans *= binpow(sum, size-2);
       	ans %= k;
       	printf("%I64d\n", ans);
	return 0;
}




// lang: GNU C++
// memory: 2100 KB
// author: imslavko
// submit_date: Mar 2, 2012 11:00:32 PM
// contest: 156
// link: /contest/156/submission/1258172
// time: 80 ms
// verdict: Accepted
// problem: 156D - Clues
// ID: 1258172
// downloaded by very stupid script
