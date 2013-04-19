#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int dp[3000][110];

int go(int sum, int n) {
	if (!n && !sum)
		return 1;
	if (!n && sum)
		return 0;
	if (dp[sum][n]+1)
		return dp[sum][n];
	int &res = dp[sum][n];
	res = 0;
	
	for (int i = 0; i <= min(sum, 25); i++) {
		res += go(sum-i,n-1);
		res %= 1000000007;
	}

	return res;
}

string s;
int main() {
	ios_base::sync_with_stdio(0);
	memset(dp, -1, sizeof dp);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> s;
		int sum = 0;
		for (int j = 0; j < (int)s.size(); j++)
			sum += s[j] - 'a';
		cout << go(sum, (int)s.size())-1 << endl;
	}

	return 0;
}





// lang: GNU C++
// memory: 2700 KB
// author: imslavko
// submit_date: Mar 2, 2012 10:22:48 PM
// contest: 156
// link: /contest/156/submission/1258056
// time: 80 ms
// verdict: Accepted
// problem: 156C - Cipher
// ID: 1258056
// downloaded by very stupid script
