#include <cstdio>
#include <cstring>

int n, x, y, d, l[101010], ans;
int main() {
	memset(l, -1, sizeof l);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		ans = 0;
		for (d = 1; d * d <= x; d++) {
			if (x % d == 0) {
				if (l[d] < i - y)
					ans++;
				if (x / d != d && l[x / d] < i - y)
					ans++;
				l[d] = l[x / d] = i;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}





// lang: GNU C++
// memory: 1700 KB
// author: imslavko
// submit_date: Sep 3, 2011 7:02:49 PM
// contest: 111
// link: /contest/111/submission/665112
// time: 440 ms
// verdict: Accepted
// problem: 111B - Petya and Divisors
// ID: 665112
// downloaded by very stupid script
