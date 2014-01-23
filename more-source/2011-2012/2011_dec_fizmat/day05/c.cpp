#include <cstdio>

int grundy(int x) {
	if (!x)
		return 0;
	if (x % 4 == 1 || x % 4 == 2)
		return x;
	if (x % 4 == 3)
		return x + 1;
	return x - 1;
}

int main() {
	freopen("nim.in", "r", stdin);
	freopen("nim.out", "w", stdout);

	int t, n, x, sum;
	scanf("%d", &t);
	
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		sum = 0;
		for (int j = 0; j < n; j++) {
			scanf("%d", &x);
			sum ^= grundy(x);
		}

		puts(sum ? "FIRST" : "SECOND");
	}	

	return 0;
}
