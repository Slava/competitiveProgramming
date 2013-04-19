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
#include <deque>

using namespace std; 

const int N = 1101010;
int n, m, ans;
int a[N], b[N], l, r, L, R;
int where[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", a+i);
		where[a[i]] = -1;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", b+i);
		where[b[i]] = i;
	}

	int size = 0;
	while (true) {
//		cout << l << " " << r << "    " << L << " " << R << "    " << size << endl;
		ans = max(ans, size);
		int next = where[a[r]];
		bool ok = false;

		if ((L < R || (L == R && !size)) && (next >= R || next < L))
			ok = true;
		if (L > R && (next >= R && next < L))
			ok = true;
		if (next == -1)
			ok = false;

		if (ok) {
			if (L == R)
				L = next;
			R = (next+1)%m;
			r = (r+1)%n;
			size++;
		} else {
			if (l == n-1)
				break;
			if (l == r)
				r = (r+1)%n;
			l = (l+1)%n;
			if (l != r)
				L = where[a[l]];
			else L = R = 0;
			size = max(size-1, 0);
		}
	}

	printf("%d\n", ans);

	return 0;
}




// lang: GNU C++
// memory: 14300 KB
// author: imslavko
// submit_date: Apr 9, 2012 1:06:01 PM
// contest: 164
// link: /contest/164/submission/1506380
// time: 840 ms
// verdict: Accepted
// problem: 164B - Ancient Berland Hieroglyphs
// ID: 1506380
// downloaded by very stupid script
