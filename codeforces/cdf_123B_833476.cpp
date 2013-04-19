/*
PROB:shuttle
ID:imslavko1
LANG:C++
*/
#include <cstdio>
#define abs(x) (x<0?-(x):x)

int mydiv(int x, int a) {
	return x >= 0 ? x/a : x/a - 1;
}

int main() {
	int a, b, x, y, xx, yy;
	scanf("%d%d%d%d%d%d", &a, &b, &x, &y, &xx, &yy);
	a <<= 1; b <<= 1;

	int x1 = mydiv(x + y, a), x2 = mydiv(x - y, b),
		y1 = mydiv(xx + yy, a), y2 = mydiv(xx - yy, b);

	int gota = abs(x1-y1), gotb = abs(x2-y2);
	printf("%d\n", gota > gotb ? gota : gotb);

	return 0;
}






// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Nov 4, 2011 7:48:40 AM
// contest: 123
// link: /contest/123/submission/833476
// time: 30 ms
// verdict: Accepted
// problem: 123B - Squares
// ID: 833476
// downloaded by very stupid script
