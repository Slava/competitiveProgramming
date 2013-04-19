#include <cstdio>
#include <cstdlib>

int d[1001][1001],
	n, m, l, r, mi;
/* START */
int main (){
	for (int i = 1; i < 1001; i++) 
		d[1][i] = i;
	for (int i = 2; i < 1001; i++) 
		for (int j = 1; j < 1001; j++) 
			d[i][j] = d[i - 1][j - 1] + d[i][j - 1] + 1;
	while (scanf("%d%d", &n, &m)){
		if (!n && !m)break;
		for (int i = 1; i <= m; i++)
			if (d[n][i] >= m){
				printf("%d\n", i);
				break;
			}
	}
	return 0;
}
