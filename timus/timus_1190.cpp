#include <cstdio>
#include <cstdlib>

char noonecares[20000];
int n, a[5100], t, l = 1, s;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s%d", noonecares, &t);
		if (!t)
			a[i] = -1;
		else scanf("%d", a + i);
	}
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] != -1)
			l = a[i];
		s += l;
	}
	if (s > 10000) {
		puts("NO");
		return 0;
	}
	l = 10000; s = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != -1)
			l = a[i];
		s += l;
	}
	if (s < 10000) {
		puts("NO");
		return 0;
	}
	puts("YES");
	return 0;
}
