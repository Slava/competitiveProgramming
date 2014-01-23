#include <cstdio>

const int NN = 1000;
int t[NN][NN], n;

void add(int x, int y, int d) {
	for (int i = x; i < n; i |= i + 1)
		for (int j = y; j < n; j |= j + 1)
			t[i][j] += d;
}

int sum(int x, int y) {
	int r = 0;
	for (int i = x; i >= 0; i &= i + 1, i--)
		for (int j = y; j >= 0; j &= j + 1, j--)
			r += t[i][j];
	return r;
}

int sum(int x1, int y1, int x2, int y2) {
	x1--,y1--;
	return sum(x2,y2) - sum(x1,y2) - sum(x2,y1) + sum(x1,y1);
}

int main () {
	return 0;
}

