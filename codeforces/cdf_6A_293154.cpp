#include <cstdio>
#include <algorithm>

int a[4];
int main ()
{
	for (int i = 0; i < 4; i++)
		scanf("%d", a + i);
	std::sort(a, a + 4);
	if (a[0] + a[1] > a[2] || a[1] + a[2] > a[3])
		puts("TRIANGLE");
	else if (a[0] + a[1] == a[2] || a[1] + a[2] == a[3])
		puts("SEGMENT");
	else puts("IMPOSSIBLE");
	return 0;
}





// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Feb 21, 2011 7:24:45 AM
// contest: 6
// link: /contest/6/submission/293154
// time: 30 ms
// verdict: Accepted
// problem: 6A - Triangle
// ID: 293154
// downloaded by very stupid script
