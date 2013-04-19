#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

typedef unsigned long long ull;
const int N = 1010;
int n, c, k, a[N][N], b[N], inf = 101010, ans[N], an;
ull K, v[N][N];

int main() {
#ifndef imslavko
	freopen("mincoin2.in", "r", stdin);
	freopen("mincoin2.out", "w", stdout);
#endif
	cin >> n >> c >> K;
	v[0][0] = (ull)1; K--;
	for (int i = n - 1; i >= 0; i--)
		cin >> b[i];
	for (int i = 0; i <= n; i++)
		for (int j = 1; j <= c; j++)
			a[i][j] = inf;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= c; j++) {
			if (a[i][j + b[i - 1]] > a[i - 1][j] + 1) {
				a[i][j + b[i - 1]] = a[i - 1][j] + 1;
				v[i][j + b[i - 1]] = 0;
			}
			if (a[i][j + b[i - 1]] == a[i - 1][j] + 1)
				v[i][j + b[i - 1]] += v[i - 1][j];
			if (a[i][j] > a[i - 1][j]) {
				a[i][j] = a[i - 1][j];
				v[i][j] = 0;
			}
			if (a[i][j] == a[i - 1][j])
				v[i][j] += v[i - 1][j];
		}
	if (a[n][c] == inf) {
		printf("-1\n");
		return 0;
	}
	int x = n, y = c;
	for (;x || y; x--)
		if (y - b[x - 1] >= 0 && a[x - 1][y - b[x - 1]] == a[x][y] - 1)
			if (v[x - 1][y - b[x - 1]] <= K)
				K -= v[x - 1][y - b[x - 1]];
			else {
				ans[an++] = n - x + 1;
				y -= b[x - 1];
			}
	sort(ans, ans + an);
	cout << an << endl;
	for (int i = 0; i < an; i++)
		cout << ans[i] << " ";
	return 0;
}
