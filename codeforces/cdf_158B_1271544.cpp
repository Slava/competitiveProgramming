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



void solve() {
	int n, x, ans = 0;
	vector<int> c(5);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		c[x]++;
	}

	ans = c[4];
	x = min(c[3], c[1]);
	c[3] -= x; c[1] -= x;
	ans += x + c[3];
	x = c[2] / 2;
	c[2] %= 2;
	ans += x;
	if (c[2]) {
		ans++;
		c[1] -= min(2,c[1]);
	}
	ans += (c[1] + 3) / 4;

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	solve();
	return 0;
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Mar 4, 2012 11:01:44 AM
// contest: 158
// link: /contest/158/submission/1271544
// time: 50 ms
// verdict: Accepted
// problem: 158B - Taxi
// ID: 1271544
// downloaded by very stupid script
