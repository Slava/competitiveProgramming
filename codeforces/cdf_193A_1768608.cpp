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

int n, m, c;
bool u[60][60];
string a[60];

void dfs(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m || u[x][y] || a[x][y] != '#')
		return;
	u[x][y] = 1;
	dfs(x-1,y);dfs(x+1,y);dfs(x,y-1);dfs(x,y+1);
}

bool check() {
	memset(u,0,sizeof u);
	int C = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (!u[i][j] && a[i][j] == '#') {
				dfs(i,j);
				C++;
			}
		}
	return C > 1;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '#') {
				c++;
				a[i][j] = '.';
				if (check()) {
					puts("1");
					return 0;
				}
				a[i][j] = '#';
			}
		}
	}

	if (c < 3)
		puts("-1");
	else
		puts("2");
	return 0;
}




// lang: GNU C++
// memory: 1500 KB
// author: imslavko
// submit_date: Jun 7, 2012 10:18:32 AM
// contest: 193
// link: /contest/193/submission/1768608
// time: 190 ms
// verdict: Accepted
// problem: 193A - Cutting Figure
// ID: 1768608
// downloaded by very stupid script
