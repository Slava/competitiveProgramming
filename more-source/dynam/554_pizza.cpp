#include <cstdio>

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n; scanf("%d", &n);
	n = n * (n + 1) / 2 + 1;
	printf("%d\n", n);
	return 0;
}
