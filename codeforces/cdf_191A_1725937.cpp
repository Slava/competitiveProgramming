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

string s;
int dp[26][26], dp2[26][26], n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < 26; j++)
			if (dp[j][s[0]-'a'])
				dp[j][s[s.size()-1]-'a'] = max(dp[j][s[s.size()-1]-'a'], dp[j][s[0]-'a']+(int)s.size());
		dp[s[0]-'a'][s[s.size()-1]-'a'] = max(dp[s[0]-'a'][s[s.size()-1]-'a'], (int)s.size());
	}

	int ans = 0;
	for (int i = 0; i < 26; i++)
		ans = max(ans, dp[i][i]);

	cout << ans << endl;
	return 0;
}




// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: May 27, 2012 7:42:10 PM
// contest: 191
// link: /contest/191/submission/1725937
// time: 800 ms
// verdict: Accepted
// problem: 191A - Dynasty Puzzles
// ID: 1725937
// downloaded by very stupid script
