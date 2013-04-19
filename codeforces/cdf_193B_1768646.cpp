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

const int N = 30;
int a[N], b[N], k[N], p[N];
int n, u, r;
long long res = -1000000000LL*1000000000LL;

void go(int left, bool justwas=0) {
	if (left%2 == 0) {
		long long R = 0;
		for (int i = 0; i < n; i++)
			R += a[i] * 1LL * k[i];
		if (R > res)
			res = R;
	}
	if (!left)return;
	int copya[N];
	for (int i = 0; i < n; i++)
		copya[i] = a[i];

	if (!justwas) {
		for (int i = 0; i < n; i++)
			a[i] = copya[i] ^ b[i];
		go(left-1, 1);
	}

	for (int i = 0; i < n; i++)
		a[i] = copya[p[i]] + r;
	go(left-1,0);
}

int main() {
	cin >> n >> u >> r;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
		cin >> k[i];
	for (int i = 0; i < n; i++)
		cin >> p[i], p[i]--;
	go(u);
	cout << res << endl;
	return 0;
}




// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Jun 7, 2012 10:36:52 AM
// contest: 193
// link: /contest/193/submission/1768646
// time: 520 ms
// verdict: Accepted
// problem: 193B - Xor
// ID: 1768646
// downloaded by very stupid script
