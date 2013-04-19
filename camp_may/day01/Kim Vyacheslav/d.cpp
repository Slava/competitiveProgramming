#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

//#define debug
typedef long long ull;

int n, k, a[1010], A, B, S;

ull dp[1010][1010], inf = (1ll << 62), ans;

bool good (int x) {
	return x >= A && x <= B;
}

void solve_stupid() {
	for (int i = 1; i <= n; i++) if (good(a[i] - a[i - 1]))
		for (int j = i + 1; j <= n; j++)
			if (good(a[j] - a[i]) && good(a[n + 1] - a[j]))
				ans = max(ans, (a[j] - a[i]) * 1ll);
	cout << ans * 2;
	exit(0);
}

ull go (int l, int kk) {
	if (!kk) {
		if (S - a[l] >= A && S - a[l] <= B)
			return 0;
		return -inf;
	}
	if (dp[l][kk])return dp[l][kk];
	ull &res = dp[l][kk],
	 was = k - kk, st = kk;
	res = -inf;
	for (int i = l + 1; i <= n; i++) {
		ull D = a[i] - a[l];
		ull d1 = D * was;
		if (D < A || D > B)continue;
		if (n - i < kk - 1ll) continue;
		ull V = go(i, kk - 1ll) + d1 * st;
		res = max(res, V);
	}
	return res;
}

int main () {
#ifndef debug
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d%d%d", &n, &k, &A, &B, &S);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	a[n + 1] = S;
	if (k < 2) {
		printf("0\n");
		return 0;
	}
	else if (k == 2)solve_stupid();
	for (int i = 1; i <= n; i++)
		if (a[i] >= A && a[i] <= B){
			ans = max(ans, go(i, k - 1));
//			cerr << go(i, k - 1) << "\n";
		}
	cout << ans * 2ll;
	return 0;
}


