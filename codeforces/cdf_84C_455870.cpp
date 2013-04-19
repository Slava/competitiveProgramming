#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std; 

int n, m, x[101010], r[101010], a[101010];
int X, Y; double d, R;
int ans[101010];

bool cmp(int i, int j){
	return x[i] < x[j];
}

void dist (int i, int j){
	if (ans[i] != -1)return;
	d = (X - x[i]) * (X - x[i]) + Y * Y;
	R = r[i] * r[i];
	if (R >= d)
		ans[i] = j;
}

/* START */
int main (){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", x + i, r + i);
		a[i] = i;
	}
	sort(a, a + n, cmp);
	scanf("%d", &m);
	memset(ans, ~0, sizeof ans);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &X, &Y);
		x[n] = X;
		int l, u;
		l = lower_bound(a, a + n, n, cmp) - a;
		u = l - 1;
		fprintf(stderr, "lu %d %d\n", l, u);
		if (l >= 0)
			dist(a[l], i + 1);
		if (u >= 0)
			dist(a[u], i + 1);
		if (++u < n)
			dist(a[u], i + 1);
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (ans[i] != -1)sum++;
	}printf("%d\n", sum);
	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}




// lang: GNU C++
// memory: 2900 KB
// author: imslavko
// submit_date: May 15, 2011 1:08:42 PM
// contest: 84
// link: /contest/84/submission/455870
// time: 270 ms
// verdict: Accepted
// problem: 84C - Biathlon
// ID: 455870
// downloaded by very stupid script
