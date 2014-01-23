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

struct event {
	int t, n, m;
	event(int _t, int _n, int _m) {
		t = _t; n = _n; m = _m;
	}
};

bool cmp (event a, event b) {
	if (a.t == b.t)
		return a.n < b.n;
	return a.t < b.t;
}

vector<event> a;

int main() {
	freopen("knifenfork.in", "r", stdin);
	freopen("knifenfork.out", "w", stdout);

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int t, l, x;
		cin >> t >> l >> x;
		a.push_back(event(t, 1, x));
		a.push_back(event(t + l, -1, -x));
	}
	
	sort(a.begin(), a.end(), cmp);

	for (int i = 0; i < (int)a.size(); i++) {
		event *it = &a[i];
		if (it->n <= n && it->m <= m) {
			n -= it->n, m -= it->m;
			if (it->n > 0)
				cout << "Yes\n";
		}
		else if (it->n > 0)
			cout << "No\n";
	}

	return 0;
}
