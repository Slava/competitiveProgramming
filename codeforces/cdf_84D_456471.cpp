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

ll k, a[101010], mx, s, ta, b[101010];
int n, was[101010], ind[101010];

bool can (ll kk){
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += min(kk, a[i]);
	}
	if (sum <= k) {
		ta = kk;
		s = sum;
		return 1;
	}
	return 0;
}

/* START */
int main (){
	scanf("%d" i64, &n, &k);
	for (int i = 0; i < n; i++) {
		scanf(i64, a + i);
		s += a[i];
		mx = max(mx, a[i]);
	}
	if (s < k){
		printf("-1\n");
		return 0;
	}
	if (s == k)return 0;
	ll l = 0, r = mx, m;
	while (l < r){
		m = (l + r) / 2ll;
		if (can(m))
			l = m + 1ll;
		else r = m - 1ll;
	}
	k -= s;int mm = 0, j = 0;
	for (int i = 0; i < n; i++) {
		a[i] = a[i] - ta;
		if (a[i] > 0)
			b[mm] = a[i],
			ind[mm++] = 1 + i;
	}
	for (; ; j++){
		if (j == mm) j = 0;
		if(!k)break; 
		if(!b[j])continue;
		k--; b[j]--;
	}
	for (; ; j++){
		if (j == mm) j = 0;
		if (was[j])break;
		was[j] = 1;
		if (!b[j])continue;
		printf("%d ", ind[j]);
	}
	return 0;
}




// lang: GNU C++
// memory: 3700 KB
// author: imslavko
// submit_date: May 16, 2011 8:08:52 AM
// contest: 84
// link: /contest/84/submission/456471
// time: 90 ms
// verdict: Accepted
// problem: 84D - Doctor
// ID: 456471
// downloaded by very stupid script
