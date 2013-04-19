#include <cstdio>
#define max(a,b) (a>b?a:b)

int inf = (1 << 30);
int n, a[200][200], u[200][200],
	d[200][200], w[200][200], q,
	son[200], dau[200], nu[200],
	wdau[200], wson[200];

void dfs(int v, int p = 0){
	for (int i = 1; i <= n; i++)
		if(a[v][i] && p != i){
			if (!son[v])
				son[v] = i, wson[v] = w[v][i];
			else dau[v] = i, wdau[v] = w[v][i];
			dfs(i, v);
			nu[v] += 1 + nu[i];
		}
}

int calc(int v, int q){
	if (q > nu[v])return -inf;
	if (!q)return 0;
	if (u[v][q])
		return d[v][q];
	int &res = d[v][q], pr;
	u[v][q] = 1;
	if (!dau[v])return res = calc(son[v], q - 1) + wson[v];
	for (int i = 1; i < q; i++){
		pr = wson[v] + wdau[v] + 
		calc(son[v], i - 1) + calc(dau[v], q - i - 1);
		res = max(res, pr);
	}
	return res = max(
		max(calc(son[v], q - 1) + wson[v], calc(dau[v], q - 1) + wdau[v]), 
					res);
}

int main () {
	scanf("%d%d", &n, &q);
	for (int i = 1; i < n; i++){
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x][y] = a[y][x] = 1;
		w[x][y] = w[y][x] = z;
	}
	dfs(1);
	printf("%d\n", calc(1, q));
	return 0;
}


