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

const int N = 210;
int n, m, k, nm, gf[N][N], g[N][N], dp[1<<7][N], id[7], c[N], u[N], used[1<<7][N];

int go(int mask, int v) {
	int &res = dp[mask][v];
	if (used[mask][v])
		return res;
	used[mask][v] = -2;
	res = 1<<30;
	int w;
	for (int i = mask; i != 0; i = (i-1)&mask)
		if (res > (w = go(mask^i,v)+go(i,v)-c[v])) {
			res = w;
			used[mask][v] = i*2;
		}
	for (int i = 0; i < nm; i++)
		if (res > (w = go(mask,i)+g[i][v])) {
			res = w;
			used[mask][v] = i*2+1;
		}
	return res;
}

void outPath(int i, int j) {
	u[i] = u[j] = 1;
	if (i == j || (i+1==j&&i%m!=m-1) || (i%m!=0&&i-1==j) || i+m==j || i-m==j)
		return;
	outPath(i,gf[i][j]);
	outPath(gf[i][j],j);
}

int firstBit(int x) {
	for (int i = 0; i < k; i++)
		if (x & (1<<i))
			return i;
	return -1;
}

void out(int mask, int v) {
	u[v] = 1;
	if (used[mask][v] == -1) {
		outPath(v,id[firstBit(mask)]);
		return;
	}
	if (used[mask][v]%2==0)
		out(mask^(used[mask][v]/2),v),
		out(used[mask][v]/2,v);
	else out(mask,used[mask][v]/2),
		outPath(v,used[mask][v]/2);
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	nm = n*m;

	for (int i = 0; i < nm; i++)
		for (int j = 0; j < nm; j++)
			g[i][j] = 1<<29;
	for (int i = 0; i < nm; i++) {
		int cost; scanf("%d", &cost);
		c[i] = cost;
		if (i-m >= 0)
			g[i-m][i] = cost;
		if (i+m < nm)
			g[i+m][i] = cost;
		if (i%m != m-1)
			g[i+1][i] = cost;
		if (i%m != 0)
			g[i-1][i] = cost;
		g[i][i] = 0;
	}

	for (int i = 0; i < k; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--; y--;
		id[i] = x*m+y;
	}

	for (int l = 0; l < nm; l++)
		for (int i = 0; i < nm; i++)
			for (int j= 0; j < nm; j++)
				if (g[i][j] > g[i][l] + g[l][j])
				g[i][j] = g[i][l]+g[l][j], gf[i][j] = l;

	for (int i = 0; i < k; i++)
		for (int j = 0; j < nm; j++)
			used[1<<i][j] = -1, dp[1<<i][j] = c[id[i]] + g[id[i]][j];

	int ans = 1<<30;
	for (int i = 0; i < nm; i++)
		ans = min(ans,go((1<<k)-1,i));
	printf("%d\n", ans);
	for (int i = 0; i < nm; i++)
		if (go((1<<k)-1,i) == ans) {
			out((1<<k)-1,i);
			break;
		}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%c", ".X"[u[i*m+j]]);
		puts("");
	}

	return 0;
}





// lang: GNU C++
// memory: 1900 KB
// author: imslavko
// submit_date: Feb 22, 2012 2:48:59 PM
// contest: 152
// link: /contest/152/submission/1215793
// time: 80 ms
// verdict: Accepted
// problem: 152E - Garden
// ID: 1215793
// downloaded by very stupid script
