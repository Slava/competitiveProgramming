#include <cstdio>
#include <algorithm>

const int N = 160;
int a[N][N][N], n, m, k, ans;

int sum(int x1, int x2, int y1, int y2, int z1, int z2) {
	x1--; y1--; z1--;
	return a[x2][y2][z2]-a[x1][y2][z2]-a[x2][y1][z2]-a[x2][y2][z1]+a[x1][y1][z2]+a[x1][y2][z1]+a[x2][y1][z1]-a[x1][y1][z1];
}

char s[N];
int main() {
	scanf("%d%d%d", &n, &m, &k);
	std::swap(m,n);
	for (int j = 1; j <= n; j++)
		for (int i = 1; i <= m; i++) {
			scanf("%s", s+1);
			for (int l = 1; l <= k; l++)
				a[i][j][l] = s[l]=='N';
		}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int l=1; l <= k; l++)
				printf("%d", a[i][j][l]);
			puts("");
		}
		puts("");
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int l = 1; l <= k; l++)
				a[i][j][l] += a[i-1][j][l] + a[i][j-1][l] + a[i][j][l-1]
							- a[i-1][j-1][l] - a[i-1][j][l-1] - a[i][j-1][l-1]
							+ a[i-1][j-1][l-1];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int len = 1; len+i-1 <= n && len+j-1 <= m; len++)
				for (int l = 1; l <= k; l++)
			   	for (int h = 1; h+l-1 <= k; h++){
					if (sum(i,i+len-1,j,j+len-1,l,l+h-1) != len*len*h)
						break;
					ans = std::max(ans, 4*len*h);
				}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int len = 1; len+i-1 <= n && len+j-1 <= m; len++)
				for (int l = 1; l <= k; l++)
			   	for (int h = 1; h+l-1 <= k; h++){
					if (sum(i,i+len-1,j,j+len-1,l,l+h-1) != len*len*h)
						break;
					if (ans == len * h * 4)
						printf("one of answers %dx%d on %d %d %d\n", h,len,i,j,l);
				}
printf("%d\n", ans);

	return 0;
}


