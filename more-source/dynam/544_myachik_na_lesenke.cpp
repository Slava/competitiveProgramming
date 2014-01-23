#include <cstdio>
#include <cstdlib>

int n;
long long a[80];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	a[0] = 1;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
		a[i + 1] += a[i],
		a[i + 2] += a[i],
		a[i + 3] += a[i];
	printf("%I64d\n", a[n]);
	return 0;
}
