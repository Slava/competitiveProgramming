#include <cstdio>


int main() {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b); n >>= 1;
	if ((a == n || a == n + 1) && (b == n || b == n + 1))
		printf("NO");
	else printf("YES");
	return 0;
}





// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Sep 3, 2011 6:46:22 PM
// contest: 112
// link: /contest/112/submission/664858
// time: 30 ms
// verdict: Accepted
// problem: 112B - Petya and Square
// ID: 664858
// downloaded by very stupid script
