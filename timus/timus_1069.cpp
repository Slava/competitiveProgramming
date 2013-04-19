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

int n, m, a[10000], d[10000];
vector<int>g[10000];

int main() {
	for (int i = 0; scanf("%d", a + m) == 1; i++) {
		a[m]--; m++;
	}
	n = m + 1;
	for (int i = 0; i < n; i++)
		d[i] = 1;
	for (int i = 0; i < m; i++)
		d[a[i]]++;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (d[j] == 1) {
				g[a[i]].push_back(j);
				g[j].push_back(a[i]);
				d[j]--; d[a[i]]--;
				break;
			}
	for (int i = 0; i < n; i++) {
		sort (g[i].begin(), g[i].end());
		printf("%d: ", i + 1);
		for (vector<int>::iterator j = g[i].begin(); j != g[i].end(); j++)
			printf("%d ", *j + 1);
		printf("\n");
	}
	return 0;
}
