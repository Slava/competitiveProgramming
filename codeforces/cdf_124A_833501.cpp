/*
PROB:shuttle
ID:imslavko1
LANG:C++
*/
#include <cstdio>

int main() {
	int n, a, b, cnt = 0;
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; i++)
		if (i - 1 >= a && n - i <= b)
			cnt++;

	printf("%d", cnt);
	return 0;
}





// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Nov 4, 2011 8:01:24 AM
// contest: 124
// link: /contest/124/submission/833501
// time: 30 ms
// verdict: Accepted
// problem: 124A - The number of positions
// ID: 833501
// downloaded by very stupid script
