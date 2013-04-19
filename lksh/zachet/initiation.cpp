#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 2100; 
long long a[N], d[N], n, k, inf = (1LL << 62);
int main() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
		d[i] = -inf;
	}
	d[n + 1] = -inf;
	scanf("%lld", &k);
	for (int i = 0; i <= n; i++)
		for (int j = i + 1; j <= i + k; j++)
			d[j] = max(a[j] + d[i], d[j]);
	printf("%lld\n", d[n + 1]);
	return 0;
}

