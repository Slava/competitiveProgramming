#include <cstdio>

int n, m, a[510], d[510][510];
bool was[510][510];

int go (int i, int m){
	if (was[i][m])return d[i][m];
	was[i][m] = 1;
	if (!m && i < n)return d[i][m] = (1 << 30);
	if (m > n - i)return d[i][m] = (1 << 30);
	if (!m && i == n)return 0;
	int &res = d[i][m], c[2] = {0, 0};
	res = (1 << 30);
	for (; i < n; i++){
		c[a[i]]++;
		int tr = c[0] * c[1] + go (i + 1, m - 1);
		if (tr < res)res = tr;
	}
	return res;
}

int main (){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	printf("%d\n", go(0, m));
	return 0;
}

