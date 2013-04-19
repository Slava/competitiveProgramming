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


int n, m, a[200][200], u[200], need, start;
vector<int>ls;

bool dfs(int v, int p = -1) {
	u[v] = 1;
	for (int i = 1; i <= n; i++)
		if (a[v][i] && i != p) {
			if (!u[i]) {
				if (dfs(i,v)) {
					if(need)ls.push_back(v);
					if (v == start)need = 0;
					return true;
				}
			}
			else {
				start = i; need = 1;
				ls.push_back(v);
				return true;
			}
		}
	return false;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}
	dfs(1);
	if (3 > (int)ls.size()) {
			fprintf(stderr, "cicl %d\n", ls.size());
		printf("NO\n");
		return 0;
	}
	for (int i = 1; i < (int)ls.size(); i++)
		a[ls[i]][ls[i - 1]] = a[ls[i - 1]][ls[i]] = 0;
	a[ls[0]][ls.back()] = a[ls.back()][ls[0]] = 0;
	memset(u, 0, sizeof u);
	for (int i = 0; i < (int)ls.size(); i++)
		if (u[ls[i]]) {
			printf("NO\n");
			fprintf(stderr, "trees are connected more then cicle");
			return 0;
		}
		else
		if (dfs(ls[i])) {
			printf("NO\n");
			fprintf(stderr, "cicle in %d\n", ls[i]);
			return 0;
		}
	for (int i = 1; i <= n; i++)
		if (!u[i]) {
			printf("NO\n");
			fprintf(stderr, "komp sv %d\n", i);
			return 0;
		}
	printf("FHTAGN!\n");
	return 0;
}




// lang: GNU C++
// memory: 1500 KB
// author: imslavko
// submit_date: Aug 7, 2011 3:40:10 PM
// contest: 103
// link: /contest/103/submission/592218
// time: 30 ms
// verdict: Accepted
// problem: 103B - Cthulhu
// ID: 592218
// downloaded by very stupid script
