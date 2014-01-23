#include <cstdio>
#include <cstdlib>

const int N = 700;
int n, m, d[] = {0,0,0,1,1,0,-1,0,0,-1,1,1,-1,-1,1,-1,-1,1};
char s[N][N];
int a[N][N], su[N][N];

int check() {
	int ok = 1, more = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int sum = 0;
			for (int o = 0; o < 18; o += 2) {
				int di = i + d[o], dj = j + d[o+1];
				if (di >= 0 && di < n && dj >= 0 && dj < m)
					sum += a[di][dj] == 1;
			}
			if (sum > s[i][j] - '0')
				ok = 0;
			if (sum < s[i][j] - '0')
				more = 1;
		}
	if (!ok)return 0;
	if (more)return 2;
	return 1;
}

int main(int argv, char **argc) {
	int seed; sscanf(argc[1], "%d", &seed); srand(seed);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int av = 0;
			if ((!i||i==n-1)&&(!j||j==m-1))
				av = 4;
			else if (!i||i==n-1||!j||j==m-1)
				av = 6;
			else av = 9;
			if (s[i][j] -'0' == av) {
				for (int o = 0; o < 18; o += 2) {
					int di = i + d[o], dj = j + d[o+1];
					if (di >= 0 && di < n && dj >= 0 && dj < m)
						a[di][dj] = 1;
				}
				continue;
			}
		}
	while (check() == 2) {
		for (bool was = 1; was; ) {
			was = 0;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					int mines = 0, free = 0;
					for (int o = 0; o < 18; o += 2) {
						int di = i + d[o], dj = j + d[o+1];
						if (di >= 0 && di < n && dj >= 0 && dj < m) {
							if (a[di][dj] == 0)free++;
							if (a[di][dj] == 1)mines++;
						}
					}
					if (mines+free == s[i][j] - '0') {
						for (int o = 0; o < 18; o += 2) {
							int di = i + d[o], dj = j + d[o+1];
							if (di >= 0 && di < n && dj >= 0 && dj < m) {
								if (a[di][dj] == 0) {a[di][dj] = 1;was=1;}
							}
						}
					}
				}
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					int mines = 0, free = 0;
					for (int o = 0; o < 18; o += 2) {
						int di = i + d[o], dj = j + d[o+1];
						if (di >= 0 && di < n && dj >= 0 && dj < m) {
							if (a[di][dj] == 0)free++;
							if (a[di][dj] == 1)mines++;
						}
					}
					if (mines == s[i][j] - '0') {
						for (int o = 0; o < 18; o += 2) {
							int di = i + d[o], dj = j + d[o+1];
							if (di >= 0 && di < n && dj >= 0 && dj < m) {
								if (a[di][dj] == 0){was=1;a[di][dj] = 2;}
							}
						}
					}
				}
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					int mines = 0, free = 0;
					for (int o = 0; o < 18; o += 2) {
						int di = i + d[o], dj = j + d[o+1];
						if (di >= 0 && di < n && dj >= 0 && dj < m) {
							if (a[di][dj] == 0)free++;
							if (a[di][dj] == 1)mines++;
						}
					}
					su[i][j] = mines;
				}
			if (!was)break;
		}
		int x = rand()%n, y = rand()%m;
		if (!a[x][y])a[x][y] = 1;
	}
	if (check() != 1)
		return 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%c", !a[i][j]?s[i][j]:".X."[a[i][j]]);
		puts("");
	}
	printf("%d\n", check());
	return 1;
}

