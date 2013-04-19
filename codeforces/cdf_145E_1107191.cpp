#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1000010 * 4;
int t[N], z[N], o[N], zo[N], oz[N];
int n, k;
char s[N];

void recnt(int v) {
	o[v] = o[v+v] + o[v+v+1];
	z[v] = z[v+v] + z[v+v+1];
	oz[v] = zo[v] = 0;
	oz[v] = max(oz[v], oz[v+v]);
	oz[v] = max(oz[v], oz[v+v+1]);
	oz[v] = max(oz[v], o[v+v] + z[v+v+1]);
	oz[v] = max(oz[v], o[v+v] + oz[v+v+1]);
	oz[v] = max(oz[v], oz[v+v] + z[v+v+1]);
	oz[v] = max(oz[v], o[v+v] + o[v+v+1]);
	oz[v] = max(oz[v], z[v+v] + z[v+v+1]);
	zo[v] = max(zo[v], zo[v+v]);
	zo[v] = max(zo[v], zo[v+v+1]);
	zo[v] = max(zo[v], z[v+v] + o[v+v+1]);
	zo[v] = max(zo[v], z[v+v] + zo[v+v+1]);
	zo[v] = max(zo[v], zo[v+v] + o[v+v+1]);
	zo[v] = max(zo[v], o[v+v] + o[v+v+1]);
	zo[v] = max(zo[v], z[v+v] + z[v+v+1]);
}

void build(int v = 1, int l = 0, int r = n - 1) {
	if (l == r) {
		if (s[l] == '7')
			o[v] = 1;
		else z[v] = 1;
		oz[v] = zo[v] = 1;
	} else {
		int m = (l + r) / 2;
		build(v+v, l, m);
		build(v+v+1,m+1,r);
		recnt(v);
	}
}

void push(int v) {
	if (t[v]) {
		t[v+v] ^= 1;
		t[v+v+1] ^= 1;
		t[v] = 0;
		swap(o[v+v],z[v+v]);
		swap(o[v+v+1],z[v+v+1]);
		swap(oz[v+v],zo[v+v]);
		swap(oz[v+v+1],zo[v+v+1]);
	}
}
void upd(int l, int r, int v = 1, int tl = 0, int tr = n - 1){
	if (l == tl && r == tr) {
		t[v] ^= 1;
		swap(o[v],z[v]);
		swap(oz[v],zo[v]);
		return;
	}
	push(v);
	int m = (tl + tr) / 2;
	if (l > m)
		upd(l,r,v+v+1,m+1,tr);
	else if (r <= m)
		upd(l,r,v+v,tl,m);
	else upd(l,m,v+v,tl,m),
		upd(m+1,r,v+v+1,m+1,tr);
	recnt(v);
}


int main() {
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	build();
	while(k--) {
		scanf("%s", s);
		if (!strcmp(s,"switch")) {
			int l, r;
			scanf("%d%d", &l, &r);
			upd(l-1,r-1);
		}
		else printf("%d\n", zo[1]);
	}

	return 0;
}




// lang: GNU C++
// memory: 83500 KB
// author: imslavko
// submit_date: Jan 22, 2012 12:40:39 PM
// contest: 145
// link: /contest/145/submission/1107191
// time: 1810 ms
// verdict: Accepted
// problem: 145E - Lucky Queries
// ID: 1107191
// downloaded by very stupid script
