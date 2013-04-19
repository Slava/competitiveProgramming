#include <cstdio>
#include <cstdlib>

int main() {
	int n, k, x, s = 0;
	scanf("%d%d", &k, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		s += x;
		s -= k;
		if (s < 0)
			s = 0;
	}
	printf("%d\n", s);
	return 0;
}
