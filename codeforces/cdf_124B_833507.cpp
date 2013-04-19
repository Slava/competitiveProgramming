/*
PROB:shuttle
ID:imslavko1
LANG:C++
*/
#include <cstdio>
#include <algorithm>

using namespace std;

int n, k, a[10], b[10][10], ans = 1 << 30;

int go(int c[]) {
	int x = 0;
	for (int i = 0; i < k; i++)
		x = x * 10 + c[a[i]];
	return x;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		char s[10];
		scanf("%s", s);
		for (int j = 0; j < k; j++) {
			b[i][j] = s[j] - '0';
			a[j] = j;
		}
	}

	do {
		int mx = 0, mn = 1 << 30;
		for (int i = 0; i < n; i++)
			mx = max(mx, go(b[i])),
			mn = min(mn, go(b[i]));
		ans = min(ans, mx - mn);
	} while(next_permutation(a, a + k));

	printf("%d\n", ans);

	return 0;
}





// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Nov 4, 2011 8:07:21 AM
// contest: 124
// link: /contest/124/submission/833507
// time: 30 ms
// verdict: Accepted
// problem: 124B - Permutations
// ID: 833507
// downloaded by very stupid script
