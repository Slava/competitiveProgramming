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

const int N = 201010;
int n, a[N], d1[N], d2[N];

string tup() {
	for (int i = 0; i < n; i++) {
		bool ok = 1;
		for (int j = 0; ok && j < (n + 1) / 2; j++) {
			int l = (i - j + n) % n,
				r = (i + j + n) % n;
			if (a[l] != a[r])
				ok = 0;
		}
		if (ok)
			return "Yes";
	}
	if (n & 1)
		return "No";
	for (int i = 0; i < n; i++) {
		bool ok = 1;
		for (int j = 0; ok && j < n / 2; j++) {
			int l = (i - 1 - j + n) % n,
				r = (i + j + n) % n;
			if (a[l] != a[r])
				ok = 0;
		}
		if (ok)
			return "Yes";
	}
	return "No";
}

string solve() {
	memset(d1, 0, sizeof d1);
	memset(d2, 0, sizeof d2);

	bool odd = n & 1;
	
	for (int i = 0; i < n; i++)
		a[i + n] = a[i];
	
	n += n;
	
	int l = 0, r = -1;
	for (int i = 0; i < n; ++i) {
		int k = (i > r ? 0 : min (d1[l+r-i], r-i)) + 1;
		while (i + k < n && i - k >= 0 && a[i + k] == a[i - k])  
			++k;
		d1[i] = --k;
		if (i+k > r)
			l = i-k,  r = i+k;
	}

	l = 0, r = -1;
	for (int i = 0; i < n; ++i) {
		int k = (i > r ? 0 : min (d2[l+r-i+1], r-i+1)) + 1;
		while (i + k - 1 < n && i - k >= 0 && a[i + k - 1] == a[i - k])  
			++k;
		d2[i] = --k;
		if (i+k-1 > r)
			l = i-k,  r = i+k-1;
	}

	for (int i = 0; i < n; i++) {
		if (d1[i]*2-odd >= n / 2)
			return "Yes";
		if (!odd && d2[i]*2 >= n / 2)
			return "Yes";
	}

	return "No";
}

int main() {
	freopen("glade.in", "r", stdin);
	freopen("glade.out", "w", stdout);

	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			scanf("%d", a + i);
		if (n < 1001)
			cout << tup() <<endl;
		else cout << solve() << endl;
	}
	return 0;
}
