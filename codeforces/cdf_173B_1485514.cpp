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

const int N = 2100;
int a[N][N], d[N];
char s[N];
int n, m;
int q[N], h, t;

int main() {
	scanf("%d%d", &n, &m);
	fill(d,d+N,10005000);
	d[n-1] = 0;
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		for (int j = 0; j < m; j++)
			if (s[j] == '#')
				a[i][n+j] = a[n+j][i] = 1;
	}

	q[t++] = n-1;
	while (h < t) {
		int v = q[h++];
		for (int i = 0; i < n+m; i++)
			if (a[v][i] && d[i] > d[v] + 1) {
				d[i] = d[v] + 1;
				q[t++] = i;
			}
	}

	int ans = d[0];
	if (ans == 10005000)
		ans = -1;
	printf("%d\n", ans);

	return 0;
}





// lang: GNU C++
// memory: 18700 KB
// author: imslavko
// submit_date: Apr 6, 2012 11:51:22 PM
// contest: 173
// link: /contest/173/submission/1485514
// time: 60 ms
// verdict: Accepted
// problem: 173B - Chamber of Secrets
// ID: 1485514
// downloaded by very stupid script
