#include <iostream>

using namespace std;

typedef long long Int;

Int n, d, l, m, p, k;
int main() {
	cin >> n >> d >> m >> l;
	for (; k < n; k++) {
		Int t = m * k, u = t + l;
		if (p >= t && p <= u)
			p += ((u - p) / d +  1) * d;
	}
	cout << p;
	return 0;
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Jul 9, 2011 4:38:25 PM
// contest: 18
// link: /contest/18/submission/539427
// time: 50 ms
// verdict: Accepted
// problem: 18B - Platforms
// ID: 539427
// downloaded by very stupid script
