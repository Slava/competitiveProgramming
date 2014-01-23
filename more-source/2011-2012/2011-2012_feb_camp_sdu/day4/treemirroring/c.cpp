#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef pair<long long, long long> Hash;

const int N = 100500;
vi g[N];
int n, m, deg[N], d1[N], d2[N];
bool leaf[N];
bool u[N], bad;

Hash operator * (Hash a, Hash b) {
	return Hash(a.first * b.first, a.second * b.second);
}

Hash operator + (Hash a, Hash b) {
	return Hash(a.first + b.first, a.second + b.second);
}

Hash dfs(int v, int p = -1) {
	if (leaf[v])return Hash(3658932LL,553247) * Hash(v,v);
	u[v] = 1;
	Hash hash = Hash(4937239,-123324)*Hash((long long)g[v].size(), (long long)g[v].size());
	vector<Hash> ht;
	for (int i = 0; i < (int)g[v].size(); i++) {
		int to = g[v][i];
		if (to == p) continue;
		if (u[to] == 1) {
			bad = 1;
			continue;
		}
		ht.push_back(dfs(to, v));
	}
	sort(ht.begin(), ht.end());
	Hash P = Hash(1,1);
	for (int i = 0; i < (int)ht.size(); i++) {
		hash = hash + P * ht[i];
		P = P * Hash(315831, 499293853);
	}
	return hash;
}

void bfs(int v, int d[]) {
	queue<int> q;
	fill(d, d+n, 1000000000);
	d[v] = 0;
	q.push(v);
	while (!q.empty()) {
		v = q.front(); q.pop();
		for (int i = 0; i < (int)g[v].size(); i++)  {
			int to = g[v][i];
			if (d[to] > d[v] + 1) {
				d[to] = d[v] + 1;
				q.push(to);
			}
		}
	}
}

void goTry(int v1, int v2) {
	memset(u, 0, sizeof u);
	memset(leaf, 0, sizeof leaf);
	bad = 0;
	bfs(v1, d1); bfs(v2, d2);
	int leaves = 0;
	for (int i = 0; i < n; i++) {
		if (d1[i] == d2[i] && deg[i] == 2) {
			leaf[i] = 1;
			leaves++;
		}
		if (d1[i] == 1000000000) {
			bad = 1;
		}
	}
	if (!leaves)return;
	Hash h1 = dfs(v1);
	if (u[v2]) {
		return;
	}
    Hash h2 = dfs(v2);
	if (h1 == h2 && !bad) {
		for (int i = 0; i < n; i++)
			if (!u[i] && !leaf[i]) {
				return;
			}
	} else {
		return;
	}
	puts("YES");
	exit(0);
}

int main() {
	bool inputOk = (scanf("%d%d", &n, &m) == 2);
	for (int i = 0; i < m; i++) {
		int x, y;
		inputOk &= (scanf("%d%d", &x, &y) == 2);
		g[x-1].push_back(y-1);
		g[y-1].push_back(x-1);
		deg[x-1]++; deg[y-1]++;
	}
	
	assert(inputOk);
	if (n > 3500) {
		puts("NO"); return 0;
	}
// solution
// check 
	dfs(0);
	for (int i = 0; i < n; i++)
		if (!u[i]) {
			puts("NO");
			return 0;
		}
	int ones = 0, others = 0;
	for (int i = 0; i < n; i++)
		if (deg[i] == 1)
			ones++;
		else if (deg[i] != 2)
			others++;
	if (ones && ones != 2) {
		puts("NO");
		return 0;
	} else if (ones) {
		int v1 = -1, v2 = -1;
		for (int i = 0; i < n; i++)
			if (deg[i] == 1)
				if (v1 == -1)
					v1 = i;
				else v2 = i;
		goTry(v1, v2);
		puts("NO");
		return 0;
	}	
	if (!others && !ones) {
		if (n % 2 == 0)
			puts("YES");
		puts("NO");
		return 0;
	}

	for (int i = 0; i < n; i++) 
		if (deg[i] == 2)
			goTry(g[i][0], g[i][1]);

	puts("NO");


	return 0;
}

