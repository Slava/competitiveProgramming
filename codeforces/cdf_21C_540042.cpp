#include <cstdio>
#define sc scanf
#define pr printf

const int N = 101010;
int n, a[N]; long long s, l, r, c;

int main() {
	sc("%d", &n);
	for (int i = 0; i < n; i++) {
		sc("%d", a + i);
		s += a[i];
	}

	if (s % 3 != 0) {
		printf("0\n");
		return 0;
	}

	s /= 3;
	for (int i = 0; i < n - 1; i++) {
		c += a[i];
		if (c == 2 * s)
			r += l;
		if (c == s)
			l++;
	}
	
	printf("%I64d", r);

	return 0;
}	





// lang: GNU C++
// memory: 1700 KB
// author: imslavko
// submit_date: Jul 10, 2011 12:39:07 AM
// contest: 21
// link: /contest/21/submission/540042
// time: 50 ms
// verdict: Accepted
// problem: 21C - Stripe 2
// ID: 540042
// downloaded by very stupid script
