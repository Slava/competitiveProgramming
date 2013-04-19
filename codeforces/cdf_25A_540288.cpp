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
#define pb push_back

vector<int>a[2];
int main() {
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x; a[x%2].pb(i + 1);
	}
	if (sz(a[0]) == 1)
		cout << a[0].back();
	else cout << a[1].back();
	return 0;
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Jul 10, 2011 7:21:29 AM
// contest: 25
// link: /contest/25/submission/540288
// time: 30 ms
// verdict: Accepted
// problem: 25A - IQ test
// ID: 540288
// downloaded by very stupid script
