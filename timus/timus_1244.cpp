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

/* START */
const int N = 1010 * 110;
int a[N], n, w[110], u[110], f[N], k, sum;
int main (){
	scanf("%d%d", &k, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", w + i);sum += w[i];
	}
	k = sum - k;
	memset(f, ~0, sizeof f);
	a[0] = 1;f[0] = 0;
	for (int i = 0; i < n; i++) {
		int v = w[i];
		for (int j = k - v; j >= 0; j--) {
			if (a[j]){
				a[j + v] += a[j];
				if (f[j + v] == -1)
					f[j + v] = i;
			}
		}
	}
	if (a[k] > 1)printf("-1\n");
	else if (!a[k])printf("0\n");
	else {
		int s = 0;
		for (int v = k; v; v -= w[f[v]]){
			u[f[v]] = 1;
			s++;
		}
		for (int i = 0; i < n; i++)
			if (u[i])printf("%d ", i + 1);
	}
	return 0;
}
