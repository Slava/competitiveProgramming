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
#include <climits>

using namespace std; 

const int N = 510;
int n, m;
int a[N][N];
int b[N][N];
int d[N][N][2];
int ans = INT_MIN;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
			b[i][j] = a[i][j];
			if (i)b[i][j] += b[i-1][j];
			if (j)b[i][j] += b[i][j-1];
			if (i&&j)b[i][j] -= b[i-1][j-1];
		}
	}
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			d[i][j][1] = a[i][j];

	int cur = 0, prv = 1;
	for (int k = 3; k <= min(n,m); k += 2) {
		for (int i = 0, x = k-1; i+k <= n; i++, x++)
			for (int j = 0, y = k-1; j+k <= m; j++, y++) {
				int sum = b[x][y];
				if (i) sum -= b[i-1][y];
				if (j) sum -= b[x][j-1];
				if (i && j) sum += b[i-1][j-1];
				d[x][y][cur] = sum - d[x-1][y-1][prv] - a[i+1][j];
				if (ans < d[x][y][cur])
					ans = d[x][y][cur];
			}
		swap(cur, prv);
	}

	printf("%d\n", ans);

	return 0;
}




// lang: GNU C++
// memory: 5500 KB
// author: imslavko
// submit_date: Apr 6, 2012 7:42:50 PM
// contest: 173
// link: /contest/173/submission/1481990
// time: 220 ms
// verdict: Accepted
// problem: 173C - Spiral Maximum
// ID: 1481990
// downloaded by very stupid script
