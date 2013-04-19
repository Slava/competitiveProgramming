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

long long b;
int n, k;
pair<int,int>a[100100];
int main() {
	cin >> n >> k >> b;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].first = -a[i].first;
		a[i].second = i;
	}
	sort(a,a+n-1);
	for (int i = 0; i < k; i++)
		b += a[i].first;
	if (b >= 0) {
		cout << n << endl;
		return 0;
	}
	int ans = 1<<30;
	for (int i = 0; i < k; i++)
		ans = min(ans, a[i].second);
	b -= a[k-1].first;
	for (int i = k; i < n; i++)
		if (b + a[i].first < 0)
			ans = min(ans, a[i].second);
	cout << ans+1 << endl;
	return 0;
}




// lang: GNU C++
// memory: 2200 KB
// author: imslavko
// submit_date: May 28, 2012 11:22:30 AM
// contest: 191
// link: /contest/191/submission/1733624
// time: 110 ms
// verdict: Accepted
// problem: 191B - Demonstration
// ID: 1733624
// downloaded by very stupid script
