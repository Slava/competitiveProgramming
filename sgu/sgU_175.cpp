#include <cstdio>

int n, p, pl, k;
int main() {
	scanf("%d%d", &n, &p);
	p--;
	while (n > 1) {
		k = n / 2;
		if (p < k) {
			pl += n - k;
			n = k;
			p = n - p - 1;
		}
		else {
			p -= k;
			n = n - k;
			p = n - p - 1;
		}
	}
	printf("%d\n", pl + p + 1);
	return 0;
}

