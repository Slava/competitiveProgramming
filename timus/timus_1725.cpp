#include <cstdio>
#include <cstdlib>

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	if (k > n / 2)
		k = n - k + 1;
	if (n == 2)
		printf("0");
	else printf("%d", n - k - 2);
	return 0;
}
