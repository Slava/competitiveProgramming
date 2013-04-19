#include <cstdio>
#include <cstdlib>

int gcd(int a, int b) {
	return a ? gcd(b%a, a) : b;
}

int main() {
	int a, b, n, k;
	scanf("%d%d%d", &a, &b, &n);
	for (int i = 0; ; i++) {
		if (i & 1) 
			k = gcd(n, b);
		else
			k = gcd(n, a);
		if(k > n) {
			printf("%d", !(i&1));
			return 0;
		}
		n -= k;
	}
	return 0;
}




// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Oct 14, 2011 7:04:34 PM
// contest: 119
// link: /contest/119/submission/767225
// time: 30 ms
// verdict: Accepted
// problem: 119A - Epic Game
// ID: 767225
// downloaded by very stupid script
