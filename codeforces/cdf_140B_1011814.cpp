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

const int N = 310;
int n, a[N], b[N][N], f[N], ff[N], ans[N], u[N], fs[N][N], s[N];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &b[i][j]), b[i][j]--;

	for (int i = 0; i < n; i++)
		scanf("%d", a + i), a[i]--;

	for (int i = 0; i < n; i++) {
		int first, second = -1;
		for (int j = 0; j < n; j++)
			if (a[j] <= i) {
				first = a[j];
				break;
			}
		for (int j = 0; j < n; j++)
			if (a[j] != first && a[j] <= i) {
				second = a[j];
				break;
			}
		f[i] = first;
		ff[first] = 1;
		s[i] = second;
		if(second +1)fs[second][first] = 1;
	}

	for (int i = 0; i < n; i++) {
		ff[i] = 0;
	//	printf("now %d, first %d\n", i, f[i]);
		if (f[i] == i)
			for (int j = 0; j < n; j++)
				if (j != i && !u[j]) {
	//				printf("I will try to ass to %d %d\n", j, i);
					int ok = 1;
					for (int k = 0; k < n && b[j][k] != i; k++)
						if ((ff[b[j][k]] || fs[b[j][k]][j]) && b[j][k] != j) {
	//						printf("cant, because %d will be better\n", b[j][k]);
							ok = 0; break;
						}
					if (ok) {
	//					printf("success\n");
						u[j] = 1;
						ans[j] = i + 1;
					}
				}
		if (u[f[i]]||s[i]==-1)continue;
	//	printf("try to ass to %d %d, second here\n", f[i], s[i]);
		int ok = 1;
		for (int k = 0; k < n && b[f[i]][k] != s[i]; k++)
			if ((ff[b[f[i]][k]] || fs[b[f[i]][k]][f[i]]) && b[f[i]][k] != f[i]) {
	//			printf("cant, because %d will be better\n", b[f[i]][k]);
				ok = 0; break;
			}
		if (ok) {
	//		printf("success\n");
			u[f[i]] = 1;
			ans[f[i]] = s[i]+1;
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]); puts("");

	return 0;
}




// lang: GNU C++
// memory: 2100 KB
// author: imslavko
// submit_date: Jan 5, 2012 8:49:32 AM
// contest: 140
// link: /contest/140/submission/1011814
// time: 60 ms
// verdict: Accepted
// problem: 140B - New Year Cards
// ID: 1011814
// downloaded by very stupid script
