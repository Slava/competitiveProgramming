#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, m, left, right, up, down;
char s[60][60];
int main() {
	left = up = 1 << 30;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", s + i);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (s[i][j] == '*') {
				up = min(up, i);
				down = max(down, i);
				left = min(left, j);
				right = max(right, j);
			}
	for (int i = up; i <= down; i++) {
		for (int j = left; j <= right; j++)
			printf("%c", s[i][j]);
		puts("");
	}
	return 0;
}




// lang: MS C++
// memory: 1400 KB
// author: imslavko
// submit_date: May 19, 2010 7:35:18 PM
// contest: 14
// link: /contest/14/submission/687540
// time: 30 ms
// verdict: Accepted
// problem: 14A - Letter
// ID: 687540
// downloaded by very stupid script
