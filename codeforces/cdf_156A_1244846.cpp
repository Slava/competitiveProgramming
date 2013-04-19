#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100100;
string s, t;
int main() {
	cin >> t >> s;
	int n = (int)s.size(), m = (int)t.size(), ans = 1<<30;
	for (int i = -max(m,n); i <= max(n,m); i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++)
			if (i+j < 0 || i+j >= m || s[j] != t[i+j])
				cnt++;
		ans = min(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Feb 29, 2012 9:38:56 PM
// contest: 156
// link: /contest/156/submission/1244846
// time: 50 ms
// verdict: Accepted
// problem: 156A - Message
// ID: 1244846
// downloaded by very stupid script
