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
#include <bitset>

using namespace std; 

const int N = 211;

int gauss(vector<bitset<N> > a, int n, int m, bitset<N> &ans) {
	vector<int> where(m, -1);
	for (int row = 0, col = 0; row < n && col < m; col++) {
		for (int i = row; i < n; i++)
			if (a[i][col]) {
				swap(a[i], a[row]);
				break;
			}
		if (!a[row][col])
			continue;
		where[col] = row;

		for (int i = 0; i < n; i++)
			if (i != row && a[i][col])
				a[i] ^= a[row];
		row++;
	}

	ans.reset();
	for (int i = 0; i < m; i++)
		if (where[i] != -1)
			ans[i] = a[where[i]][m] / a[where[i]][i];

	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++)
			sum ^= a[i][j] * ans[j];
		if (sum ^ a[i][m])
			return 0;
	}

	return 1;
}

void out(bitset<N>& a, int n) {
	int k = 0;
	for (int i = 0; i < n; i++)
		k += a.test(i);
	printf("%d\n", k);
	for (int i = 0; i < n; i++)
		if (a.test(i))
			printf("%d ", i + 1);
	puts("");
	exit(0);
}

int main() {
	int n;
	scanf("%d", &n);
	vector<bitset<N> > a(n, bitset<N>());

	for (int i = 0; i < n; i++) {
		int k; scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			int x; scanf("%d", &x);
			a[x-1][i] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		a[i][n] = x;
	}

/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + 1; j++)
			printf("%d ", a[i].test(j));
		puts("");
	}
*/

	bitset<N> ans;
	if (gauss(a, n, n, ans))
		out(ans, n);
	for (int i = 0; i < n; i++)
		a[i][n] = a[i].test(n) ^ 1;
	if (gauss(a, n, n, ans))
		out(ans, n);
	puts("-1");

	return 0;
}
