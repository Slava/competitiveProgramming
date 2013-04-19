#include <cstdio>

int f(int x) {
	int s = 0, l;
	for (int i = 2; i <= x; i++)
		if (x % i == 0) {
			s += l = i;
			while (x % i == 0)
				x /= i;
		}
	s -= l;
	return l - s;
}

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	a = f(a); b = f(b);
	printf(a > b ? "a" : "b");
	return 0;
}

