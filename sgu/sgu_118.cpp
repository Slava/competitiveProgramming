#include <cstdio>
#include <cstdlib>

int f(int n) {
	if (n % 9 == 0 && n > 8)
		return 9;
	return n % 9;
}

int main() {
	int k, n; scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &n);
		int sum = 0, mult = 1, x;
		for (int j = 0; j < n; j++) {
			scanf("%d", &x);
			mult = f(mult*f(x));
			sum = f(sum+mult);
		}
		printf("%d\n", sum);
	}

	return 0;
}
