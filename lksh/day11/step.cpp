#include <cstdio>
#include <cstdlib>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a<b?b:a)

const int N = 600000;
int n, m, ans[N], prf[2][N], suf[2][N], p, x, a[N/3];

void upd(int i = 1, int l = 0, int r = n - 1) {
	if (l == r) {
		ans[i] = prf[x][i] = suf[x][i] = 1;
		prf[x^1][i] = suf[x^1][i] = 0;
		return;
	}
	int m = (l + r) / 2, ll = m - l + 1, lr = r - m, L = i + i, R = i + i + 1;
	if (p > m) upd(R, m + 1, r);
	else upd(L, l, m);
	ans[i] = max(ans[L], ans[R]);
	for (int j = 0; j < 2; j++) {
		ans[i] = max(ans[i], suf[j][L] + prf[j^1][R]);
//		printf("will dp prf[%d], prf[j][L] = %d, ll = %d, prf[bla][R] = %d\n",
//				j,prf[j][L], ll, prf[j^(ll&1)][R]);
		prf[j][i] = prf[j][L] + (prf[j][L] == ll ? prf[j^(ll&1)][R] : 0);
//		printf("will dp suf[%d], suf[j][R] = %d, lr = %d, suf[bla][L] = %d\n",
//				j,suf[j][R], lr, suf[j^(lr&1)][L]);
		suf[j][i] = suf[j][R] + (suf[j][R] == lr ? suf[j^(lr&1)][L] : 0);
	}
//	printf("i %d L %d R %d $ prf0 %d prf1%d suf0 %d suf1 %d ans %d\n", i, l, r, prf[0][i], prf[1][i], suf[0][i], suf[1][i], ans[i]);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < N; i++)
		ans[i] = prf[0][i] = suf[0][i] = 1;
	for (int i = 0; i < m; i++) {
		scanf("%d", &p); p--;
		x = (a[p] ^= 1); upd();
		printf("%d\n", ans[1]);
	}
	return 0;
}
