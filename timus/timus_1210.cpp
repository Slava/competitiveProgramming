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

// n + i <- pr + x
const int N = 1000;
int k, n, l, pr, a[N][N], g[N][N], ans = (1 << 30);
char s[700];
int main() {
	scanf("%d", &k); n = 1;
	for (int z = 0; z < k; z++) {
		scanf("%d", &l);
		for (int i = 0; i < l; i++) {
			for (int x, y; ;) {
				scanf("%d", &x);
				if (!x) break;
				scanf("%d", &y); x--;
				a[pr + x][n + i] = 1;
				g[pr + x][n + i] = y;
			}
		}
		if(z != k - 1)scanf("%s", s);
		pr = n; n += l;
	}
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (a[i][k] && a[k][j]) {
					if (!a[i][j] || g[i][j] > g[i][k] + g[k][j])
						g[i][j] = g[i][k] + g[k][j];
					a[i][j] = 1;
				}
	for (int i = n - l; i < n; i++) {
		if (!a[0][i])continue;
		ans = min(ans, g[0][i]);
	}
	printf("%d", ans);
	return 0;
}
