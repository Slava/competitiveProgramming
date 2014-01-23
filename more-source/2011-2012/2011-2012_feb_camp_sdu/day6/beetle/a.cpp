#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 310;
int n, x[N], m, ans, pl;
int dp[N][N][N][2];

int go(int l, int r, int k, bool onRight) {
	if (!k) return 0;
	int &res = dp[l][r][k][onRight];
	if (res+1)return res;
	res = 1<<30;
	if (onRight) {
		if (r != n-1)
			res = min(res, k*(x[r+1]-x[r])+go(l,r+1,k-1,1));
		if (l)
			res = min(res, k*(x[r]-x[l-1])+go(l-1,r,k-1,0));
	} else {
		if (r != n-1)
			res = min(res, k*(x[r+1]-x[l])+go(l,r+1,k-1,1));
		if (l)
			res = min(res, k*(x[l]-x[l-1])+go(l-1,r,k-1,0));
	}

//	printf("dp %d %d %d %d  %d\n", l, r, k, onRight, res);
	return res;
}


int main() {
	memset(dp, -1, sizeof dp);

	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", x+i);
		if (x[i] == 0)
			pl = m;
	}

	if (!pl) x[n++] = 0;
	sort(x,x+n);
	int p = lower_bound(x,x+n,0)-x;
	int ans = 0;
	
	for (int i = 0; i <= n; i++)
		ans = max(ans, i*m-go(p,p,i,0));

	printf("%d\n", ans+pl);

	return 0;
}

