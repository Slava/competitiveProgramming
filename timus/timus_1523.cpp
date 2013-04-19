#include <cstdio>
#include <cstdlib>
#include <cstring>

int n, k, a[20100], ans;
int MOD = 1000000000;
struct fenwik {
	int t[20100];
	fenwik() {memset(t, 0, sizeof t);}
	void inc(int i, int x) {
		x %= MOD;
		for (; i <= n; i |= i + 1)
			t[i] = (t[i] + x) % MOD;
	}
	int su(int i) {
		int r = 0;
		for (; i >= 0; i &= i + 1, i--)
			r = (r + t[i]) % MOD;
		return r % MOD;
	}
	int sum(int l, int r) {
		return (((su(r) - su(l - 1)) % MOD) + MOD) % MOD;
	}
}t[10];

int main (){
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < k - 1; j++) {
			t[j].inc(a[i], t[j - 1].sum(a[i] + 1, n));
		}
		ans = (ans + t[k - 2].sum(a[i] + 1, n)) % MOD;
		t[0].inc(a[i], 1);
	}
	printf("%d\n", (ans % MOD + MOD) % MOD);
	return 0;
}
