//#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <fstream>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long Int;
typedef pair<int,int> ii;
#define sz(x) ((int)x.size())
#define pb push_back
#define forc(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); ++i)
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)

int n, k, t[201010], a[101010], b[101010], c[101010], d[101010];

void update(int i, int x) {
	i += n; t[i] = x;
	while (i > 1) {
		i /= 2;
		t[i] = max(t[i + i], t[i + i + 1]);
	}
}

int get(int l, int r) {
	int res = -(1 << 30);
	l += n; r += n;
	while (l <= r) {
		if (l & 1)
			res = max(res, t[l]);
		if (!(r & 1))
			res = max(res, t[r]);
		l = (l + 1) / 2; r = (r - 1) / 2;
	}
	return res;
}

void out() {
	int mx = get(0, n - 1);
	if (mx == -(1 << 30))
		puts("Nothing");
	else printf("%d\n", mx);
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		b[i] = d[i] = a[i];
		update(i, -(1 << 30));
	}
	sort(b, b + n);
	int N = unique(b, b + n) - b;
	for (int i = 0; i < n; i++)
		a[i] = lower_bound(b, b + N, a[i]) - b;
	for (int i = 0; i < k; i++) {
		c[a[i]]++;
		if (1 == c[a[i]])
			update(a[i], d[i]);
		else update(a[i], -(1 << 30));
	}
	out();
	for (int i = k, j = 0; i < n; i++, j++) {
		c[a[j]]--;
		if (1 == c[a[j]])
			update(a[j], d[j]);
		else update(a[j], -(1 << 30));
		c[a[i]]++;
		if (1 == c[a[i]])
			update(a[i], d[i]);
		else update(a[i], -(1 << 30));
		out();
	}
	return 0;
}





// lang: GNU C++
// memory: 3700 KB
// author: imslavko
// submit_date: Jul 12, 2011 4:45:23 PM
// contest: 69
// link: /contest/69/submission/543150
// time: 160 ms
// verdict: Accepted
// problem: 69E - Subsegments
// ID: 543150
// downloaded by very stupid script
