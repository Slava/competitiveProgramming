#include <cstdio>

int u[50][1010], a[50][1010];
int r (int n, int k){
	if (u[n][k] != 0)return a[n][k];
	u[n][k] = 1;
	int &res = a[n][k];
	if (!n)return res = k ? 0 : 1;
	for (int i = 0; i < 10; i++)
		if(k - i >= 0)
			res += r(n - 1, k - i);
	return res;
}

int main () {
	int n, k, ans;
	scanf("%d%d", &n, &k);
	if (k & 1){printf("0");return 0;}
	ans = r(n, k / 2) * r(n, k / 2);
	printf("%d\n", ans);
	return 0;
}

