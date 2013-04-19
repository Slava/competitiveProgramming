#include <cstdio>
#include <cstdlib>

int a[100100], n, k;

int go(int start) {
	int i = start;
	if (i < 1) i = 1;
	for (; i < n; i++)
		if (a[i] == 4 && a[i + 1] == 7)
			if (i & 1) {
				a[i + 1] = 4;
				return i + 1;
			}
			else {
				a[i] = 7;
				return i;
			}
	return -1;
}

int main() {
	scanf("%d %d\n", &n, &k);
	for (int i = 1; i <= n; i++) {
		char c; scanf("%c", &c);
		a[i] = c - '0';
	}

	int p, prevp = -1;
	while(k--) {
		p = go(prevp - 1);
		if (p == -1) break;
		if (p / 2 == prevp / 2)
			k &= 1;
		prevp = p;
	}

	for (int i = 1; i <= n; i++)
		printf("%d", a[i]);

	return 0;
}




// lang: GNU C++
// memory: 1700 KB
// author: imslavko
// submit_date: Oct 28, 2011 7:38:47 AM
// contest: 122
// link: /contest/122/submission/810473
// time: 50 ms
// verdict: Accepted
// problem: 122D - Lucky Transformation
// ID: 810473
// downloaded by very stupid script
