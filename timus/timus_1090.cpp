#include <cstdio>
#include <cstdlib>
#include <cstring>

int t[10100], n, k, ans, x, s, an;

void inc(int i) {
	for (; i < 10100; i |= i + 1)
		t[i]++;
}

int sum(int i) {
	int r = 0;
	for (; i >= 0; i = (i & (i + 1)) - 1)
		r += t[i];
	return r;
}

int main (){
	ans = -1;
	scanf("%d%d", &n, &k);
	for (int j = 1; j <= k; j++) {
		memset(t, 0, sizeof t); s = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			s += sum(10000) - sum(x);
			inc(x);
		}
		if (ans < s) {
			ans = s;
			an = j;
		}
	}
	printf("%d", an);
	return 0;
}
