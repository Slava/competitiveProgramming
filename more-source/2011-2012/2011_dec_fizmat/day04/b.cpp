#include <cstdio>
#include <cstdlib>

int n, k;
int main() {
	freopen("squares.in", "r", stdin);
	freopen("squares.out", "w", stdout);

	scanf("%d%d", &n, &k);
	int best = 100000000, x, y;
	for (int i = 1; i * i <= k; i++)
		if (k % i == 0) {
			int X = k / i, Y = i, per = (X + 1) * 2 + (Y + 1) * 2;
			if (per < best) {
				best = per;
				x = X; y = Y;
			}
		}

	if (best > n) {
		puts("NO");
		return 0;
	}

	if ((n - best) % 2 == 1) {
		puts("NO");
		return 0;
	}

	puts("YES");
	int X = 0, Y = 0;
	puts("0 0");
	for (int i = 1; i <= (n - best) / 2; i++) {
		Y++;
		printf("%d %d\n", X, Y);
	}

	for (int i = 0; i <= y; i++) {
		Y++;
		printf("%d %d\n", X, Y);
	}

	for (int i = 0; i <= x; i++) {
		X++;
		printf("%d %d\n", X, Y);
	}

	for (int i = 0; i <= y; i++) {
		Y--;
		printf("%d %d\n", X, Y);
	}

	for (int i = 0; i < x; i++) {
		X--;
		printf("%d %d\n", X, Y);
	}

	for (int i = 1; i <= (n - best) / 2; i++) {
		Y--;
		printf("%d %d\n", X, Y);
	}
	return 0;
}
