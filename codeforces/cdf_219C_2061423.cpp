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

#define abs(x) (x<0?-(x):x)

int n, k;
string s;

const int N = 600000;
int dp[N][4], from[N][4];
// A,B,C,X

int main() {
	cin >> n >> k >> s;
	if (k == 2) {
		int res = 0, ress = 0;
		for (int i = 0; i < n; i++) {
			res += s[i] != ('A'+i%2);
			ress += s[i] != ('B'-i%2);
		}
		cout << min(res,ress) << endl;
		for (int i = 0; i < n; i++)
			if (res < ress)
				cout << char('A'+i%2);
			else
				cout << char('B'-i%2);
		cout << endl;
		return 0;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 4; j++)
			dp[i][j] = 1<<29;

	if (s[0] <= 'C') {
		for (int i = 0; i < min(4,k); i++)
			dp[0][i] = 1;
		dp[0][s[0]-'A'] = 0;
	} else
		dp[0][0] = dp[0][1] = dp[0][2] = 1,
		dp[0][3] = 0;

	for (int i = 0; i < n-1; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++) {
				if ((k < 3 && j < 3 && k == j) 
					|| (k == 3 && j == 3 && s[i] == s[i+1]))
					continue;
				if (k == 3 && s[i+1] < 'D')
					continue;
				int ch = k!=3&&s[i+1]!=('A'+k);
				if (dp[i+1][k] > dp[i][j]+ch) {
		//			cout << i << "    " << j << " " << k << " " << s[i] << " " << s[i+1] << " " << ch << endl;
					dp[i+1][k] = dp[i][j]+ch;
					from[i+1][k] = j;
				}
			}

	int m = 0;
	for (int i = 0; i < 4; i++)
		if (dp[n-1][i] < dp[n-1][m])
			m = i;

	cout << dp[n-1][m] << endl;
	string ans;
	for (int i = n-1; i >= 0; i--) {
		if (m < 3)
			ans += 'A'+m;
		else
			ans += s[i]>'C'?s[i]:'D';
		m = from[i][m];
	}

	reverse (ans.begin(), ans.end());
	cout << ans << endl;

	return 0;
}




// lang: GNU C++
// memory: 21600 KB
// author: imslavko
// submit_date: Aug 28, 2012 5:18:33 AM
// contest: 219
// link: /contest/219/submission/2061423
// time: 160 ms
// verdict: Accepted
// problem: 219C - Color Stripe
// ID: 2061423
// downloaded by very stupid script
