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

int n, a[500200], m, mm, p;
int main() {
	scanf("%d", &n);
	for (int j = 1; j <= n; j++) {
		for (int i = 0; i < j; i++)
			a[m++] = 2;
		a[m++] = 1;
	}
	for (int j = n - 1; j > 0; j--) {
		for (int i = 0; i < j; i++)
			a[m++] = 2;
		a[m++] = 1;
	}
	for (int j = 2; j <= n; j++) {
		for (int i = 0; i < j; i++) {
			a[mm] *= p ? -1 : 1;
			mm++;
		}
		p ^= 1;
	}
	for (int i = 0; i < n; i++) {
		a[mm] *= p ? -1 : 1;
		mm++;
	} p ^= 1;
	for (int j = n; j >= 1; j--) {
		for (int i = 0; i < j; i++) {
			a[mm] *= p ? -1 : 1;
			mm++;
		}
		p ^= 1;
	} p = n - 1;printf("%d\n%d", mm + 1, p);
	for (int i = 0; i < m; i++) {
		p += a[i]; printf(" %d", p);
	}
	return 0;
}
