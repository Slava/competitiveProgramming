#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1010;
int n, k[N], a[N][N];
int cr, pr;
bool d[N][N];

int main() {

	freopen("moose.in", "r", stdin);
	freopen("moose.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", k + i); k[i]--;
		for (int j = 0; j < k[i]; j++)
			scanf("%d", a[i] + j);
	}
	pr = 1 << 30;
	for (int i = 0; i < k[0]; i++)
		d[0][i] = 1, pr = min(pr, a[0][i]);
	for (int i = 1; i < n; i++) {
		cr = -1;
		for (int j = 0; j < k[i]; j++) {
			d[i][j] = (pr != -1 && a[i][j] >= pr);
			if (d[i][j]) {
				if (cr == -1)
					cr = a[i][j];
				else cr = min(cr, a[i][j]);
			}
		}
		pr = cr;
	}

	int ans = -1;
	for (int i = 0; i < k[n - 1]; i++)
		if (d[n - 1][i] && ans < a[n - 1][i])
			ans = a[n - 1][i];
	printf("%d\n", ans);
	return 0;
}
