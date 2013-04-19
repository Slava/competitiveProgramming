#include <cstdio>

int a['   '], b['  '], c['  '], i, j, k, n, m;
bool go() {
	for (i = 0; i < n; i++) {
		k = 0;
		for (j = 1; j <= m; j++)
			if (c[j] && (!i || j != a[i - 1]) && (i != n - 1 || j != a[0])
				&& c[k] < c[j]) k = j;
		if (!k) 
			return 0;
		a[i] = k; c[k]--;
	}
	return 1;
}

bool go2() {
	for (i = 0; i < n; i++) {
		k = 0;
		for (j = 1; j <= m; j++)
			if (b[j] && (!i || j != a[i - 1]) && (i != n - 1 || j != a[0])
				&& b[k] <= b[j]) k = j;
		if (!k) 
			return 0;
		a[i] = k; b[k]--;
	}
	return 1;
}

int main() {
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++)
		scanf("%d", b + i), c[i] = b[i];
	if (!go() && !go2()) {
		printf("-1");
		return 0;
	}
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
}





// lang: GNU C++
// memory: 9600 KB
// author: imslavko
// submit_date: Jul 9, 2011 8:34:20 PM
// contest: 81
// link: /contest/81/submission/539769
// time: 30 ms
// verdict: Accepted
// problem: 81D - Polycarps Picture Gallery
// ID: 539769
// downloaded by very stupid script
