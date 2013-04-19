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


const int N = 200;
int dp[N][N][N][2], n, m;
char s[N][N];

bool test(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
	int count[N]; memset(count, 0, sizeof count);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
		for (int j = 0; j < m; j++)
			count[i] += s[i][j] == 'W';
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k <= 150; k++)
				dp[i][j][k][0] = dp[i][j][k][1] = (1 << 30);
	dp[0][0][s[0][0] == 'W'][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			for (int k = 0; k <= m; k++) {
				if (m - 1 != j) {
					int K = s[i][j + 1] == 'W'; K += k;
					dp[i][j + 1][K][0] = min(dp[i][j + 1][K][0], dp[i][j][k][0] + 1);
				}
				if (i != n - 1 && k == count[i]) {
					int K = s[i + 1][j] == 'W';
					dp[i + 1][j][K][1] = min(dp[i + 1][j][K][1], dp[i][j][k][0] + 1);
				}
			}
		for (int j = m - 1; j >= 0; j--)
			for (int k = 0; k <= m; k++) {
				if (j != 0) {
					int K = s[i][j - 1] == 'W'; K += k;
					dp[i][j - 1][K][1] = min(dp[i][j - 1][K][1], dp[i][j][k][1] + 1);
				}
				if (i != n - 1 && k == count[i]) {
					int K = s[i + 1][j] == 'W';
					dp[i + 1][j][K][0] = min(dp[i + 1][j][K][0], dp[i][j][k][1] + 1);
				}
			}
	}
	int ans=  (1 << 30);
	int lst = n - 1;
	while (lst >= 0 && !count[lst])
		lst--;
	if (lst >= 0)
	for (int j =0; j < m; j++)
		ans = min(ans, min(dp[lst][j][count[lst]][0],
							dp[lst][j][count[lst]][1]));
	if (lst < 0)
		ans = 0;
	cout << ans;
	return 0;
}




// lang: GNU C++
// memory: 64000 KB
// author: imslavko
// submit_date: Sep 15, 2011 7:01:14 PM
// contest: 115
// link: /contest/115/submission/704506
// time: 90 ms
// verdict: Accepted
// problem: 115B - Lawnmower
// ID: 704506
// downloaded by very stupid script
