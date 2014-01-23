#pragma comment(linker, "/STACK:16777216")
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
int t[801010], flag[801010];

void upd(int l, int r, int x, int i = 1, int tl = 0, int tr = 101010 - 1) {
	if (l == tl && r == tr) {
		flag[i] = 1;
		t[i] = x;
	}else {
		if (flag[i]) {
			flag[i] = 0;
			flag[i+i] = flag[i+i+1] = 1;
			t[i+i]=t[i+i+1] = t[i];
		}
		int tm = (tl + tr) / 2;
		if (l > tm)
			upd(l,r,x,i+i+1,tm+1,tr);
		else if (r <= tm)
			upd(l,r,x,i+i,tl,tm);
		else {
			upd(l,tm,x,i+i,tl,tm);
			upd(tm+1,r,x,i+i+1,tm+1,tr);
		}
	}
}

int get(int x, int i = 1, int l = 0, int r = 101010 - 1) {
	if (flag[i])return t[i];
	if (l == r)
		return 0;
	int m = (l+r)/2;
	if (x<=m)
		return get(x,i+i,l,m);
	return get(x,i+i+1,m+1,r);
}

#define x first.first
#define y first.second
#define id second
#define l first.first
#define r first.second
#define X second
#define mp make_pair


typedef pair<pair<int,int>,int> ppiii;
int h, w, n;
ppiii a[201010];
int ans[201010];

int main() {
	scanf("%d%d%d", &w, &h, &n);
	for (int i = 0; i < n; i++) {
		double xx, yy;
		scanf("%lf%lf", &xx, &yy);
		a[i].x = (int)(xx * 2);
		a[i].y = (int)(yy * 2);
		a[i].id = i;
	}
	sort(a,a+n);
	for (int i = 0; i < n; i++) {
		int rad = a[i].x - get(a[i].y);
		ans[a[i].id] = rad;
		upd(a[i].y-rad,a[i].y+rad-1, a[i].x+rad);
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", ans[i]);
	return 0;
}
