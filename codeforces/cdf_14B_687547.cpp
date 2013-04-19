#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 110;
int n, x0, a[N], b[N], ans = (1<<30);

bool good(int x) {
	for (int i = 0; i < n; i++)
		if (x < a[i] || x > b[i])
			return 0;
	return 1;
}

int main() {
	scanf("%d%d", &n, &x0);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", a + i, b + i);
		if (a[i] > b[i])
			swap(a[i], b[i]);
	}
	for (int i = 0; i <= 1000; i++)
		if (good(i))
			ans = min(abs(i - x0), ans);
	if (ans == (1<<30))
		ans = -1;
	printf("%d\n", ans);
	return 0;
}




// lang: MS C++
// memory: 1400 KB
// author: imslavko
// submit_date: May 19, 2010 7:43:05 PM
// contest: 14
// link: /contest/14/submission/687547
// time: 30 ms
// verdict: Accepted
// problem: 14B - Young Photographer
// ID: 687547
// downloaded by very stupid script
