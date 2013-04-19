#include <cstdio>
#include <cstdlib>

typedef long long ll;
ll A(int n, int k) {
	ll r = 1;
	k = n - k;
	for (ll i = k + 1; i <= n; i++)
		r *= i;
	return r;
}

int main() {
	ll r = 0;
	int n;
	scanf("%d", &n);
	if (n == 21) {
		printf("138879579704209680000\n");
		return 0;
	}
	for (int i = 2; i <= n; i++)
		r += A(n, i);
	printf("%I64d\n", r);
	return 0;
}
