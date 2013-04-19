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
#define pb push_back

const int N = 55;
int dp[N][N][2];
int n, pos, d[N];

int go(int L, int R, int onL) {
	int &res = dp[L][R][onL];
	if (~res)
		return res;
	res = 1<<30;
	if (L == R)
		return res;
	int meter = n-R+L+1, cur = onL ? d[L] : d[R];
	if (onL) {
		res = min(res,1+go(L+1,R,1)+abs(cur-d[L+1])*meter);
		res = min(res,1+go(L+1,R,0)+abs(cur-d[R])*meter);
	} else {
		res = min(res,1+go(L,R-1,1)+abs(cur-d[L])*meter);
		res = min(res,1+go(L,R-1,0)+abs(cur-d[R-1])*meter);
	}
	//cerr << L << " " << R <<  " " << onL << " " << res << endl;
	return res;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> d[i];
	cin >> pos;
	d[n++] = pos;
	sort(d,d+n);
	memset(dp,-1,sizeof dp);
	pos = lower_bound(d,d+n, pos) - d;
	dp[pos][pos][0] = 0;
	cout << min(go(0,n-1,0),go(0,n-1,1)) << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	if (fopen("greenbiathlon.in", "r")) {
		freopen("greenbiathlon.in", "r", stdin);
		freopen("greenbiathlon.out", "w", stdout);
	}

	int T;
	cin >> T;
	while (T--)
		solve();

	return 0;
}
