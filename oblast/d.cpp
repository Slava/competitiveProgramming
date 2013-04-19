#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, a[510][510], p[510], win[510];
int b[510];

void simulate() {
	for (int i = 0; i < n; i++)
		b[p[i]+n] = i;
	for (int i = n - 1; i > 0; i--)
		b[i] = a[b[i+i]][b[i+i+1]] ? b[i+i] : b[i+i+1];
	win[b[1]] = 1;
}

int main() {
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);

	for (int i = 0; i < 510; i++)
		p[i] = i;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);

	if (n > 11)
		memset(win, 1, sizeof win);
	else
		do simulate(); while(next_permutation(p,p+n));
	
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += win[i];

	printf("%d\n", cnt);
	for (int i = 0; i < n; i++)
		if (win[i])
			printf("%d ", i + 1);
	puts("");

	return 0;
}
