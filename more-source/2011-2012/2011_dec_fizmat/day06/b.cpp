#include <cstdio>
#include <cstdlib>

int a[4], n, c, sum;
int main() {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);

	for (int i = 0; i < 4; i++) {
		scanf("%d", a + i);
		sum ^= a[i];
		if (a[i] > 1)
			c++;
	}

	puts((!sum && !c) || (sum && c) ? "First wins." : "Second wins.");
	return 0;
}
