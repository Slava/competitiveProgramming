#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long Int;
#define sz(x) ((int)x.size())

int x, y, a, b;

bool can(int c) {
	Int A = a * 1ll * c;
	Int B = b * 1ll * c;
	return (x >= A && y >= B);// || (x >= B && y >= A);
}

int main() {
	cin >> x >> y >> a >> b;
	int g = __gcd(a, b); a /= g; b /= g;
	int l = 0, r = 1000000000, m;
	while (l <= r) {
		m = (l + r) / 2;
		if (can(m))
			l = m + 1;
		else r = m - 1;
	}
	
	--l;
	cout << l * a << " " << l * b;

	return 0;
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Jul 10, 2011 3:57:26 AM
// contest: 16
// link: /contest/16/submission/540167
// time: 30 ms
// verdict: Accepted
// problem: 16C - Monitor
// ID: 540167
// downloaded by very stupid script
