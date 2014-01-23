#include <cstdio>
#include <cstdlib>

#ifdef WIN32
#define i64 "%I64d"
#else
#define i64 "%lld"
#endif

const int N = 101010;
long long t[N], x;
int n;

void inc(int i, long long x) {
	for (; i <= n; i |= i + 1)
		t[i] += x;
}

long long get(int i) {
	long long r = 0;
	for (; i >= 0; i &= i + 1, i--)
		r += t[i];
	return r;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(i64, &x);
		inc(i, x); inc(i + 1, -x);
	}

	while(~scanf(i64, &x))
		if (x == 1) {
			int l, r;
			scanf("%d%d" i64, &l, &r, &x);
			inc(l, x); inc(r + 1, -x);
		} else {
			scanf(i64, &x);
			printf(i64 "\n", get(x-1));
		}

	return 0;
}

