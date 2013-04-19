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

int n, A[7200], c[2], m;
vector<int>g[7200];

int main() {
	scanf("%d", &n);
	for (int i = 0, k; i < n; i++) {
		scanf("%d", &k);
		for (int j = 0, x; j < k; j++) {
			scanf("%d", &x); x--;
			g[i].push_back(x);
		}
	}
	for (;;) {
		bool was = 0;
		for (int i = 0; i < n; i++) {
			int s = 0;
			for (vector<int>::iterator j = g[i].begin(); j != g[i].end(); j++)
				s += A[i] == A[*j];
			if (s > 1) {
				A[i] ^= 1;
				was = 1;
			}
		}
		if (!was)break;
	}
	for (int i = 0; i < n; i++)
		c[A[i]]++;
	if (c[1] < c[0] || (c[1] == c[0] && A[0]))
		m = 1;
	printf("%d\n", c[m]);
	for (int i = 0; i < n; i++)
		if(A[i] == m)
			printf("%d ", i + 1);
	return 0;
}

