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
#include <cassert>

using namespace std; 

struct event {
	int x, o, l, r;
	event(int _x, int _o, int _l, int _r) {
		x = _x;
		o = _o;
		l = _l;
		r = _r;
	}

	bool operator < (const event &b)const {
		return x != b.x ? x < b.x : o > 0;
	}
};

vector<event> events;
int n;

// interval tree [-10^8,10^8]
const int N = /*1000*2*30*8+-100500*/ 340500;
int nodes, lson[N], rson[N], Min[N];
long long pl[N], sum[N];

void create(int &v, int l, int r) {
	v = ++nodes;
	assert(v!=N);
	sum[v] = (r-l+1);
}

#define updinfo(v) sum[v] = 0; \
		Min[v] = min(Min[lson[v]], Min[rson[v]]); \
		if (Min[lson[v]] == Min[v]) \
			sum[v] += sum[lson[v]]; \
		if (Min[rson[v]] == Min[v]) \
			sum[v] += sum[rson[v]]; \
		if (tl == tr) \
			sum[v] = 1; \
		Min[v] += pl[v]; 

int BOUND = 100000000;
void upd(int l, int r, int d, 
	int v = 1, int tl = 0, int tr = 2*BOUND) {
	if (tl != tr) {
		if (!lson[v]) create(lson[v], tl, (tl+tr)/2);
		if (!rson[v]) create(rson[v], (tl+tr)/2+1,tr);
	}
	if (l == tl && r == tr) {
		pl[v] += d;
		updinfo(v);
	} else {
		int tm = (tl+tr)/2;
		if (l > tm)
			upd(l,r,d,rson[v],tm+1,tr);
		else if (r <= tm)
			upd(l,r,d,lson[v],tl,tm);
		else upd(l,tm,d,lson[v],tl,tm),
			upd(tm+1,r,d,rson[v],tm+1,tr);
		updinfo(v);
	}
}

long long get() {
	if (Min[1] > 0)
		return (BOUND*2+1);
	return BOUND*2+1 - sum[1];
}
// interval tree

int main() {
	freopen("planting.in", "r", stdin);
	freopen("planting.out", "w", stdout);

	int root;
	create(root, -BOUND, BOUND);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x1,x2,y1,y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if (x1>x2)swap(x1,x2);
		if (y1>y2)swap(y1,y2);
		events.push_back(event(x1,1,y1,y2));
		events.push_back(event(x2,-1,y1,y2));
	}

	sort (events.begin(), events.end());

	long long prvx = events[0].x, ans = 0;
	for (int i = 0; i < (int)events.size(); i++) {
		event cur = events[i];
		ans += (cur.x - prvx) * get();
		prvx = cur.x;
		upd(cur.l+BOUND, cur.r-1+BOUND, cur.o);
	}

#ifdef WIN32
	printf("%I64d\n", ans);
#else
	printf("%Ld\n", ans);
#endif

	return 0;
}
