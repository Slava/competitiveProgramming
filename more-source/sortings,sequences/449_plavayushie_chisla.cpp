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

int L, n, a[200], c; 

int main() {
#ifndef imslavko
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	scanf("%d%d", &L, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	sort(a, a + n);
	for (int i = 0, j; i < n; i++) {
		for (j = 0; j < n; j++)
			if (a[j] - a[i] > L * 2)
				break;
		c++; i = j - 1;
	}
	printf("%d\n", c);
	return 0;
}
