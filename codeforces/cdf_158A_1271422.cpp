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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	int min = a[k-1], ans = 0;
	for (int i = 0; i < n; i++)
		if (a[i] >= min && a[i] > 0)
			ans++;
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
// submit_date: Mar 4, 2012 10:55:30 AM
// contest: 158
// link: /contest/158/submission/1271422
// time: 30 ms
// verdict: Accepted
// problem: 158A - Next Round
// ID: 1271422
// downloaded by very stupid script
