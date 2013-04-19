#include <cstdio>
#include <cstdlib>

char s[200][200];
int n, m, ans, a[200][200];

int ch(int x, int y) {
	if (s[x][y] != 'W')
		return 0;
	if (a[x][y])
		return 0;
	a[x][y] = 1;
	return 1;
}

int main() {
	scanf("%d%d",&n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (s[i][j] == 'P')
				ans += ch(i, j - 1) | ch(i,j+1)|ch(i-1,j)|ch(i+1,j);
	printf("%d\n", ans);
	return 0;
}




// lang: GNU C++
// memory: 1500 KB
// author: imslavko
// submit_date: Sep 15, 2011 7:08:05 PM
// contest: 116
// link: /contest/116/submission/696507
// time: 30 ms
// verdict: Accepted
// problem: 116B - Little Pigs and Wolves
// ID: 696507
// downloaded by very stupid script
