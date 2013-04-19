#include <cstdio>
#include <cstdlib>

const int N = 101010;
int n, m, t[N], a[N];

void upd(int i, int x) {
	for (; i < n; i |= i + 1)
		t[i] += x;
}

int sum(int i) {
	int r = 0;
	for (; i >= 0; i &= i + 1, i--)
		r += t[i];
	return r;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		upd(i, 1), a[i] = 1;
	for (int i = 0; i < m; i++) {
		int l, r, c;
		scanf("%d", &c);
		if (c == -1) {
			scanf("%d", &l); l--;
			if (a[l]) {
				a[l]--; upd(l, -1);
			}
		}
		if (c == 1) {
			scanf("%d", &l); l--;
			if (!a[l]) {
				a[l]++; upd(l, 1);
			}
		}
		if (!c) {
			scanf("%d%d", &l, &r); l--, r--;
			printf("%s\n", sum(r) - sum(l - 1) == r - l + 1 ? "PASSED" : "PENALTY");
		}
	}
	return 0;
}
