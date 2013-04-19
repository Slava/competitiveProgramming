#include <cstdio>
#include <cstdlib>
#include <cstring>

const int N = 100;
#define int long long
int a[N], n, d[N][N];
bool kn[N][N];

int get(int L, int R) {
	if (R - L < 2)
		return 0;
	if (kn[L][R])
		return d[L][R];
	int ans = (1 << 30), t;
	for (int i = L + 1; i < R; i++) {
		t = get(L, i) + get(i, R) + a[i] * (a[L] + a[R]);
		if (ans > t)
			ans = t;
	}
	kn[L][R] = 1;
	return d[L][R] = ans;
}
main() {
	scanf("%lld", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", a + i);
	printf("%lld\n", get(0, n - 1));
	return 0;
}
