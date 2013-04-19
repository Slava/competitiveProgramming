#include <cstdio>

typedef long long Int;

#ifdef WIN
#define i64 "%I64d"
#else
#define i64 "%Ld"
#endif

Int f[20], x;
int main() {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	
	scanf(i64, &x);
	f[0] = 1;
	for (int i = 1; i < 20; i++)
		f[i] = f[i-1] * i;
	
	for (int mask = 0; mask < (1 << 20); mask++) {
		Int res = 0;
		for (int i = 0; i < 20; i++)
			if (mask & (1 << i))
				res += f[i];
		if (res == x) {
			bool first = 1;
			for (int i = 0; i < 20; i++)
				if (mask & (1 << i)) {
					if (!first)
						printf("+");
					printf("%d!", i);
					first = 0;
				}
			puts("");
			return 0;
		}
	}

	puts("Impossible");

	return 0;
}
