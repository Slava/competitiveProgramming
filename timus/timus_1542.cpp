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
#pragma comment(linker, "/STACK:16777216")

pair<string, int>da[201010];
int n, m, inf = (1 << 30); string q;
char buff[500];
int t[401010], maxlen;

void build(int i = 1, int l = 0, int r = n - 1) {
	if (l == r)
		t[i] = l;
	else {
		int m = (l + r) / 2;
		build(i + i, l, m); build(i + i + 1, m + 1, r);
		t[i] = da[t[i + i]].second >= da[t[i + i + 1]].second ? t[i + i] : t[i + i + 1];
	}
}

void update(int p, int x, int i = 1, int l = 0, int r = n - 1) {
	if (l == r)
		t[i] = x;
	else {
		int m = (l + r) / 2;
		if (p <= m)
			update(p, x, i + i, l, m);
		else update(p, x, i + i + 1, m + 1, r);
		t[i] = da[t[i + i]].second >= da[t[i + i + 1]].second ? t[i + i] : t[i + i + 1];
	}
}

int getmax(int l, int r, int i = 1, int tl = 0, int tr = n - 1) {
	if (l == tl && r == tr)
		return t[i];
	int m = (tl + tr) / 2;
	if (l > m)
		return getmax(l, r, i + i + 1, m + 1, tr);
	if (r <= m)
		return getmax(l, r, i + i, tl, m);
	int a = getmax(l, m, i + i, tl, m), b = getmax(m + 1, r, i + i + 1, m + 1, tr);
	return da[a].second >= da[b].second ? a : b;
}

void rec(int l, int r, int c) {
	if (c <= 0)return;
	int num = getmax(l, r), t = da[num].second;
	printf("%s\n", da[num].first.c_str());
	da[num].second = -inf;
	update(num, num);
	rec(l, r, c - 1);
	da[num].second = t;
	update(num, num);
}

/* START */
int main (){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", buff);
		da[i].first = buff;
		scanf("%d", &da[i].second);
		maxlen = max(maxlen, (int)da[i].first.size());
	}
	sort(da, da + n);
	build();

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%s", buff); q = buff;
		int l = lower_bound(da, da + n, make_pair(q, -inf)) - da,
			r = upper_bound(da, da + n, make_pair(q + string(max(0, (int)(maxlen - (int)q.size())), 'z'), inf)) - da - 1;
	if (l > r || l < 0 || r < 0 || l >= n || r >= n);
		else rec(l, r, min(10, r - l + 1));
		if (i != m - 1)printf("\n");
	}

	return 0;
}

