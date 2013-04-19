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

int n, m, k;
char a[55][55];
int u[55][55][4][2];

int d[] = {0,1,1,0,0,-1,-1,0}, dp, cp = -1;
int ls[50010000];
int lsk;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%s", a[i] + 1);
	}
	m = strlen(a[1] + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] -= '0';

	int x = 1, y = 1;
	for (int K = 0; K < k; K++) {
		if(u[x][y][dp][cp==1]) {
			int pl = K - u[x][y][dp][cp==1] + 1;
			while (K < k)
				K += pl;
			K -= pl;
		}
//		printf("%d %d %d %d %d\n", x, y, dp, cp, K);fflush(stdout);
		u[x][y][dp][cp==1] = K + 1;
		int dx = x, dy = y;
		while (a[dx][dy] == a[x][y])
			dx += d[dp*2], dy += d[dp*2+1];
		dx -= d[dp*2]; dy -= d[dp*2+1];
		int dcp = (dp + cp + 4) % 4;
		while (a[dx][dy] == a[x][y])
			dx += d[dcp*2], dy += d[dcp*2+1];
		dx -= d[dcp*2]; dy -= d[dcp*2+1];
		if (a[dx+d[dp*2]][dy+d[dp*2+1]] > 0) {
			x = dx + d[dp*2]; y = dy + d[dp*2+1];
		}
		else if (cp == -1)
			cp = 1;
		else {
			cp = -1;
			dp = (dp + 1) % 4;
		}
//		printf("%d %d %d %d %d\n", x, y, dp, cp, K);fflush(stdout);
	}

	printf("%d\n", a[x][y]);
	return 0;
}




// lang: GNU C++
// memory: 197200 KB
// author: imslavko
// submit_date: Dec 3, 2011 7:38:57 PM
// contest: 132
// link: /contest/132/submission/922709
// time: 30 ms
// verdict: Accepted
// problem: 132B - Piet
// ID: 922709
// downloaded by very stupid script
