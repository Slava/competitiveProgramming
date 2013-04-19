#include <cstdio>
#define sc scanf
#define pr printf

int n, m;
long long x[1010], y[1010], res;
char s[1010][1010];

int main() {
	sc("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		sc("%s", s[i]);
		for (int j = 0; j < m; j++)
			if (s[i][j] == '*')
				x[i]++, y[j]++;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (s[i][j] == '*')
				res += (x[i] - 1) * (y[j] - 1);
	printf("%I64d", res);
	return 0;
}





// lang: GNU C++
// memory: 2400 KB
// author: imslavko
// submit_date: Jul 10, 2011 12:45:36 AM
// contest: 52
// link: /contest/52/submission/540049
// time: 50 ms
// verdict: Accepted
// problem: 52B - Right Triangles
// ID: 540049
// downloaded by very stupid script
