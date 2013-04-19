#include <cstdio>
#include <cstdlib>

const int N = 110;
int a[N], b[N], c[N], d[N], n, v[N], ans = (1 << 30), V;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d%d%d", a + i, b + i, c + i, d + i);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (a[j] > a[i] && b[j] > b[i] && c[j] > c[i])
				v[i] = 1;
		if (!v[i] && ans > d[i])
			ans = d[i], V = i;
	}
	printf("%d", V + 1);
	return 0;
}




// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Aug 19, 2011 7:09:02 PM
// contest: 106
// link: /contest/106/submission/688324
// time: 30 ms
// verdict: Accepted
// problem: 106B - Choosing Laptop
// ID: 688324
// downloaded by very stupid script
