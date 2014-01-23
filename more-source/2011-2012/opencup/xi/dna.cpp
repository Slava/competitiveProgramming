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


const int N = 10000;
int k, ok;
int a[N], b[N], beg[N*2], end[N*2];
int u[N], p[N*2];

void dfs(int v, int U = 1) {
	u[v] = U;
	for (int i = p[a[v]+1]; i < b[v] && ok; i = p[i+1])
		if (beg[i]+1) {
			if (b[beg[i]] < b[v])
				continue;
			if (u[beg[i]] && u[beg[i]] == u[v]) {
				ok = 0;
				return;
			}else if(!u[beg[i]])
				dfs(beg[i], U*-1);
		} else if (end[i]+1) {
			if (a[end[i]] > a[v])
				continue;
			if (u[end[i]] && u[end[i]] == u[v]) {
				ok = 0;
				return;
			} else if(!u[end[i]])
				dfs(end[i], U*-1);
		}
}

void solve() {
	if (!k)return;
	memset(beg, -1, sizeof beg);
	memset(end, -1, sizeof end);
	memset(u, 0, sizeof u);

	for (int i = 0; i <= k*2; i++)
		p[i] = i;

	for (int i = 0; i < k; i++) {
		scanf("%d%d", a+i, b+i);
		if (a[i] > b[i])
			swap(a[i], b[i]);
		beg[a[i]] = i;
		end[b[i]] = i;
	}

	for (int i = k*2; i > 0; i--)
		if (beg[i-1]==-1&&end[i-1]==-1)
			p[i-1]=p[i];
	ok = 1;
	for (int i = 0; ok && i < k; i++)
		if (!u[i])
			dfs(i);
	if (!ok)printf("im");
	puts("possible");
}

int main() {
#ifndef imslavko
	freopen("dna.in", "r", stdin);
	freopen("dna.out", "w", stdout);
#endif
	
	while(~scanf("%d", &k))
		solve();

	return 0;
}
