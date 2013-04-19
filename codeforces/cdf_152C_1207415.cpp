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

#ifdef WIN32
#define i64 "%I64d"
#else
#define i64 "%lld"
#endif

typedef long long ll;

ll ans = 1;
vector<char> s[200];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		for (int j = 0; j < m; j++)
			s[j].push_back(t[j]);
	}

	for (int i = 0; i < m; i++) {
		sort(s[i].begin(),s[i].end());
		ans *= unique(s[i].begin(),s[i].end())-s[i].begin();
		ans %= 1000000007LL;
	}

	cout << ans << endl;
	return 0;
}




// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Feb 20, 2012 7:20:18 PM
// contest: 152
// link: /contest/152/submission/1207415
// time: 50 ms
// verdict: Accepted
// problem: 152C - Pocket Book
// ID: 1207415
// downloaded by very stupid script
