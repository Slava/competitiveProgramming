#include <cstdio>
#include <cstdlib>
#include <cstring>

const int N = 100100, K = 26;

int last, sz;
int len[N], suff[N];
int link[N][K];
bool terminate[N], clonned[N];

int conv(char c) {
	return c - 'a';
}

void init() {
	sz = 1;
	memset(link[0], -1, sizeof link[0]);
	memset(terminate, 0, sizeof terminate);
	memset(clonned, 0, sizeof clonned);
	len[0] = 0; suff[0] = -1; last = 0;
}

void add_char(int c) {
	int newv = sz++, v;
	memset(link[newv], -1, sizeof link[newv]);
	len[newv] = len[last] + 1;

	for (v = last; v != -1; v = suff[v])
		if (link[v][c] == -1)
			link[v][c] = newv;
		else break;
// 1
	if (v == -1)
		suff[newv] = 0;
	else {
		int u = link[v][c];
		// 2.a
		if (len[v] + 1 == len[u])
			suff[newv] = u;
		else {
			// 2.b
			int clone = sz++;
			len[clone] = len[v] + 1;
			memcpy(link[clone], link[u], sizeof link[u]);
			suff[clone] = suff[u];
			clonned[clone] = 1;

			for (; v != -1 && link[v][c] == u; v = suff[v])
				link[v][c] = clone;

			suff[newv] = suff[u] = clone;
		}
	}
	last = newv;
}

void make_terminate() {
	for (int v = last; v != -1; v = suff[v])
		terminate[v] = 1;
}

