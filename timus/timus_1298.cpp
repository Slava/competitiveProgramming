#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std; 

int d[] = {1,2, 2,1, -1,2, 2,-1, 1,-2, -2,1, -1,-2, -2,-1};
int n, a[9][9];
char b[] = "abcdefgh";

bool test(int x, int y) {
	return !(x < 0 || x >= n || y < 0 || y >= n || a[x][y]);
}

int count(int x, int y) {
	int r = 0;
	for (int i = 0; i < 16; i += 2)
		r += test(x + d[i], y + d[i + 1]);
	return r;
}

int main() {
	scanf("%d", &n);
	if (n > 1 && n < 5) {
		puts("IMPOSSIBLE");
		return 0;
	}
	int x, y, best, m; x = y = 0;
	for (int k = 0; k < n * n; k++) {
		printf("%c%d\n", b[x], y + 1);
		a[x][y] = 1;
		m = 100; best = 0;
		for (int i = 0; i < 16; i += 2)
			if (test(x + d[i], y + d[i + 1])) {
				int t = count(x + d[i], y + d[i + 1]);
				if (t < m) {
					m = t;
					best = i;
				}
			}
		x += d[best]; y += d[best + 1];
	}
	return 0;
}

