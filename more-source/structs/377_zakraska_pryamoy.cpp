#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

pii a[50000];
int n, L, N, ans;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int l, r; scanf("%d%d", &l, &r);
		a[i] = pii(l, 0);
		a[i + n] = pii(r, 1);
	}

	sort(a, a + n + n);
	L = a[0].first; N = !a[0].second;
	for (int i = 1; i < n + n; i++) {
		int C = a[i].first;
		if (N > 0)
			ans += C - L;
		if (!a[i].second)
			N++;
		else N--;
		L = C;
	}

	printf("%d\n", ans);

	return 0;
}
