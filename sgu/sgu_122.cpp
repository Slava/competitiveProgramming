#include <cstdio>
#include <algorithm>
#include <sstream>

const int N = 1010;
int n, p[N];
bool a[N][N];
char s[N*200];

int main() {
	scanf("%d\n", &n);

	for (int i = 0; i < n; i++) {
		gets(s);
		std::stringstream st;
		st << s;

		int x;
		while (st >> x)
			a[i][x-1] = 1;
		p[i] = i;
	}

	for (int k = 0; k < n; k++) {
		int i, j;
		for (i = 0; i < n; i++)
			if (!a[p[i]][p[i+1]])
				break;
		if (i == n)
			break;
		for (j = 0; j < n; j++)
			if (i!=j && j!=i+1 && j!=i-1
			&& a[p[i+1]][p[j+1]] && a[p[i]][p[j]])
				break;
		if (j >= n)
			break;
		int *beg = p+i+1, *end = p+j+1;
		if (beg > end)
			std::swap(beg,end);
		std::reverse(beg,end);
	}

	for (int i = 0; i < n; i++)
		printf("%d ", p[i]+1);
	printf("%d\n", p[0]+1);

	return 0;
}
