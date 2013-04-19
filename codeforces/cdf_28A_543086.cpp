#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

void NO() {
	puts("NO");
	exit(0);
}

int n, m, x[600], y[600], l[600], u[600], ans[600];

bool doit(int k) {
	memset(u, 0, sizeof u);
	memset(ans, -1, sizeof ans);
	for (int i = 1 + k; i <= n + k; i += 2) {
		if (((x[i - 1] - x[i]) && (y[i - 1] - y[i])) || 
			((x[i + 1] - x[i]) && (y[i + 1] - y[i])))
			NO();
		int pr = abs(x[i - 1] - x[i]) + abs(y[i - 1] - y[i]);
		int ne = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
		for (int j = 0; j < m; j++)
			if (!u[j] && l[j] == ne + pr) {
				u[j] = 1; ans[i] = j + 1; break;
			}
		if (ans[i] == -1)
			return 0;
	}
	ans[k] = ans[k + n];
	if (k) ans[0] = ans[n];
	return 1;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d%d", x + i, y + i);
	for (int i = 0; i < m; i++)
		scanf("%d", l + i);
	x[n] = x[0]; y[n] = y[0];
	x[n + 1] = x[1]; y[n + 1] = y[1];
	x[n + 2] = x[2]; y[n + 2] = y[2];
	if (doit(0) || doit(1)) {
		puts("YES");
		for (int i = 0; i < n; i++)
			printf("%d ", ans[i]);
	}
	else puts("NO");
	return 0;
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Jul 12, 2011 3:52:09 PM
// contest: 28
// link: /contest/28/submission/543086
// time: 30 ms
// verdict: Accepted
// problem: 28A - Bender Problem
// ID: 543086
// downloaded by very stupid script
