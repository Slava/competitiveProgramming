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

#ifdef WIN32
#define i64 "%I64d"
#else
#define i64 "%lld"
#endif

typedef long long ll;

int n, m, k, x, y;
ll ans;

int go(int x, int n, int dx) {
	int dist;
	if (dx < 0) {
		dx = -dx;
		dist = x;
	}else dist = n-x-1;
	if (!dx)return 1<<30;
	return dist / dx;
}

int main() {
	scanf("%d%d%d%d%d", &n,&m,&x,&y,&k);
	x--;y--;
	for (int i = 0; i < k; i++) {
		int dx, dy;
		scanf("%d%d", &dx, &dy);
		int cof = min(go(x,n,dx),go(y,m,dy));
		ans += cof;
		x += dx * cof;
		y += dy * cof;
	}

	printf(i64 "\n", ans);

	return 0;
}




// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Feb 20, 2012 7:12:47 PM
// contest: 152
// link: /contest/152/submission/1206797
// time: 50 ms
// verdict: Accepted
// problem: 152B - Steps
// ID: 1206797
// downloaded by very stupid script
