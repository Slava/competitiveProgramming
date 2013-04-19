#include <cstdio>
#include <cstdlib>

#define max(a,b) (a>b?a:b)
#define dbg(X) for(int z = 0; z < n; z++)printf("%d ", X[k][z]);

int a[2][1500], dg[2][1500], gd[2][1500], v[2][1500], p[2], h[1500], n, k;
char m[1500];
int main (){
	scanf("%d%s", &n, m);
	for (int i = 0; i < n; i++)
		a[0][i] = m[i] == 'S';
	p[a[0][0]] = 1; h[0] = 1;
	for (int i = 1; i < n; i++) {
		if (a[0][i] == a[0][i - 1])
			h[i] = h[i - 1] + 1;
		else h[i] = 1;
		p[a[0][i]] = max(p[a[0][i]], h[i]);
	}
	for (int i = 0; i < n; i++)
		dg[0][i] = gd[0][i] = v[0][i] = 1;
	for (int j = 1; j < n; j++) {
		scanf("%s", m);
		k = j & 1;
		for (int i = 0; i < n; i++)
			a[k][i] = m[i] == 'S';
		p[a[k][0]] = max(p[a[k][0]], 1); h[0] = 1;
		for (int i = 1; i < n; i++) {
			if (a[k][i] == a[k][i - 1])
				h[i] = h[i - 1] + 1;
			else h[i] = 1;
			p[a[k][i]] = max(p[a[k][i]], h[i]);
		}
		dg[k][0] = 1;
		for (int i = 1; i < n; i++) {
			if (a[k][i] == a[k^1][i - 1])
				dg[k][i] = dg[k^1][i - 1] + 1;
			else dg[k][i] = 1;
			p[a[k][i]] = max(p[a[k][i]], dg[k][i]);
		}
		gd[k][n - 1] = 1;
		for (int i = n - 2; i >= 0; i--) {
			if (a[k][i] == a[k^1][i + 1])
				gd[k][i] = gd[k^1][i + 1] + 1;
			else gd[k][i] = 1;
			p[a[k][i]] = max(p[a[k][i]], gd[k][i]);
		}
		for (int i = 0; i < n; i++) {
			if (a[k][i] == a[k^1][i])
				v[k][i] = v[k^1][i] + 1;
			else v[k][i] = 1;
			p[a[k][i]] = max(p[a[k][i]], v[k][i]);
		}
	}
	if (p[0] > p[1])printf("s\n%d", p[0]);
	if (p[0] < p[1])printf("S\n%d", p[1]);
	if (p[0] == p[1])printf("?\n%d", p[0]);
	return 0;
}
