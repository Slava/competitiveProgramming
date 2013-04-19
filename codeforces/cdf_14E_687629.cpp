#include <cstdio>
#include <cstdlib>

typedef long long Int;
int n, t;
Int d[20][11][2][4], ans;

int main() {
	scanf("%d%d", &n, &t);
	for (int i = 1; i < 4; i++)
		d[1][0][1][i] = i;
	for (int i = 1; i < n; i++)
		for (int j = 0; j <= t; j++)
			for (int k = 0; k < 4; k++)
				for (int l = 1; l < 4; l++) {
					if (k - l >= 0 && j) 
						d[i][j][0][k - l] += d[i - 1][j - 1][1][k];
					if (k + l < 4) 
						d[i][j][1][k + l] += d[i - 1][j][0][k];
					if (k - l >= 0)
						d[i][j][0][k - l] += d[i - 1][j][0][k];
					if (k + l < 4)
						d[i][j][1][k + l] += d[i - 1][j][1][k];
				}
	for (int i = 0; i < 4; i++)
		ans += d[n - 1][t][0][i];
	printf("%lld\n", ans);
	return 0;
}




// lang: MS C++
// memory: 1400 KB
// author: imslavko
// submit_date: May 19, 2010 8:31:47 PM
// contest: 14
// link: /contest/14/submission/687629
// time: 30 ms
// verdict: Accepted
// problem: 14E - Camels
// ID: 687629
// downloaded by very stupid script
