#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <bitset>

#include <cmath>
#include <cstring>

using namespace std; 



const int N = 20100;
int n, a[N], ans;

void go(int k) {
	if (n/k < 3)
		return;
	for (int i = 0; i < k; i++) {
		int cnt = 0;
		for (int j = i; j < n; j += k)
			cnt += a[j];
		if (ans < cnt)
			ans = cnt;
	}
}

void solve() {
	ans = -1e9;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 1; i * i <= n; i++)
		if (n % i == 0) {
			go(i);
			go(n/i);
		}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	solve();
	return 0;
}





// lang: GNU C++
// memory: 1500 KB
// author: imslavko
// submit_date: Mar 4, 2012 11:52:59 AM
// contest: 158
// link: /contest/158/submission/1272481
// time: 30 ms
// verdict: Accepted
// problem: 158D - Ice Sculptures
// ID: 1272481
// downloaded by very stupid script
