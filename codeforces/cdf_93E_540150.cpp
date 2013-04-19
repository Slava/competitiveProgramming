#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long Int;

const int N(100), M(300000);
Int dp[N][M], k;
int n, a[N];

Int get(int n, Int k) {
	if (n == -1)
		return 1;
	if (k < M) {
		if (dp[n][k] != -1)
			return dp[n][k];
		return dp[n][k] = k / a[n] + get(n - 1, k) - get(n - 1, k / a[n]);
	}
	return k / a[n] - get(n - 1, k / a[n]) + get(n - 1, k);
}

int main() {
	cin >> k >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	memset(dp, -1, sizeof dp);
	cout << k - get(n - 1, k);
	return 0;
}






// lang: GNU C++
// memory: 236200 KB
// author: imslavko
// submit_date: Jul 10, 2011 3:21:26 AM
// contest: 93
// link: /contest/93/submission/540150
// time: 1090 ms
// verdict: Accepted
// problem: 93E - Lostborn
// ID: 540150
// downloaded by very stupid script
