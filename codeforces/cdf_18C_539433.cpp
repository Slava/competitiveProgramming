#include <iostream>

using namespace std;

int a[101010], n, s, l, ans;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
	}
	for (int i = 0; i < n - 1; i++) {
		s -= a[i]; l += a[i];
		if (l == s)
			ans++;
	}
	cout << ans;
	return 0;
}





// lang: GNU C++
// memory: 1800 KB
// author: imslavko
// submit_date: Jul 9, 2011 4:41:25 PM
// contest: 18
// link: /contest/18/submission/539433
// time: 140 ms
// verdict: Accepted
// problem: 18C - Stripe
// ID: 539433
// downloaded by very stupid script
