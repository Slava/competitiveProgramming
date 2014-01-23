// Kim Vyacheslav KarKTL
#include <cstdio>

#define N 100000
#define min(a,b) (a<b?a:b)

int a[N], t[N * 2], n;
void build() {
	for (int i = 0; i < n; i++)
		t[i + n] = a[i];
	for (int i = n - 1; i >= 1; i--)
		t[i] = min(t[i + i], t[i + i + 1]);
}

int getmin(int l, int r) {
	int ans = (1 << 30);
	l += n; r += n;
	while (l <= r) {
		if (l & 1) ans = min(ans, t[l]);
		if (!(r & 1)) ans = min(ans, t[r]);
		l = (l + 1) / 2;
		r = (r - 1) / 2;
	}
	return ans;
}

void update(int i, int x) {
	i += n; t[i] = x;
	while(i > 1) {
		i >>= 1;
		t[i] = min(t[i + i], t[i + i + 1]);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	build();
	return 0;
}

