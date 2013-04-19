#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int p[200], n, a[200], d;

int get(int x) {
	if (p[x] != x)
		p[x] = get(p[x]);
	return p[x];
}

void unite(int x, int y) {
	x = get(x); y = get(y);
	if (x == y)return ;
	if (rand() & 1)
		swap(x, y);
	p[x] = y;
}

int main() {
	for (int i = 1; i <= 100; i++)
		p[i] = i;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &d);
		if (i - d > 0)unite(i - d, i);
		if (i + d <= n) unite(i + d, i);
	}
	for (int i = 1; i <= n; i++)
		if (get(i) != get(a[i])) {
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Jul 12, 2011 3:52:54 PM
// contest: 28
// link: /contest/28/submission/543090
// time: 30 ms
// verdict: Accepted
// problem: 28B - pSort
// ID: 543090
// downloaded by very stupid script
