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

int p = 2;

int gauss (vector < vector<int> > a, vector<int> & ans) {
	int n = (int) a.size();
	int m = (int) a[0].size() - 1;
 
	vector<int> where (m, -1);
	for (int col=0, row=0; col<m && row<n; ++col) {
		int sel = row;
		for (int i=row; i<n; ++i)
			if (abs (a[i][col]) > abs (a[sel][col]))
				sel = i;
		if (a[sel][col] == 0)
			continue;
		for (int i=col; i<=m; ++i)
			swap (a[sel][i], a[row][i]);
		where[col] = row;
 
		for (int i=0; i<n; ++i)
			if (i != row) {
				int c = a[i][col] / a[row][col];
				for (int j=col; j<=m; ++j) {
					a[i][j] -= a[row][j] * c;
					a[i][j] = (a[i][j]+p)%p;
				}
			}
		++row;
	}
 
	ans.assign (m, 0);
	for (int i=0; i<m; ++i)
		if (where[i] != -1)
			ans[i] = a[where[i]][m] / a[where[i]][i];
	for (int i=0; i<n; ++i) {
		int sum = 0;
		for (int j=0; j<m; ++j)
			sum += ans[j] * a[i][j];
		if (sum - a[i][m])
			return 0;
	}
 
	for (int i=0; i<m; ++i)
		if (where[i] == -1)
			return -1;
	return 1;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<vector<int> > a(n, vector<int>(n+1,0));
	for (int i = 0; i < n; i++) {
		int x;
		while (true) {
			scanf("%d", &x);
			if (x == -1)
				break;
			a[x-1][i] = 1;
		}
		a[i][n] = 1;
	}

	vector<int> ans;
	if (gauss(a, ans) == 1) {
		for (int i = 0; i < n; i++)
			if (ans[i])
				printf("%d ", i+1);
	} else printf("No solution");
	puts("");

	return 0;
}
