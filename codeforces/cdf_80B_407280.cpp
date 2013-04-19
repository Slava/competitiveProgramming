#include <cstdio>

int h, m;
double a, b;
int main (){
	scanf("%d:%d", &h, &m);
	h %= 12;
	if (h) a += h * 360.0 / 12.0;
	if (m) a += m * 360.0 / 60.0 / 12.0;
	if (m) b += m * 360.0 / 60.0;
	printf("%lf %lf", a, b);
	return 0;
}





// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Apr 25, 2011 10:23:50 AM
// contest: 80
// link: /contest/80/submission/407280
// time: 30 ms
// verdict: Accepted
// problem: 80B - Depression
// ID: 407280
// downloaded by very stupid script
