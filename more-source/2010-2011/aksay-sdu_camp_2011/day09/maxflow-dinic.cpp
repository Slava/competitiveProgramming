#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const long MAXN = 501;
long INF = 1 << 30;
long n, c[MAXN][MAXN], f[MAXN][MAXN], s, t, d[MAXN], ptr[MAXN], q[MAXN];

bool bfs() {
	long qh=0, qt=0;
	q[qt++] = s;
	memset (d, -1, n * sizeof d[0]);
	d[s] = 0;
	while (qh < qt) {
		long v = q[qh++];
		for (int to=0; to<n; ++to)
			if (d[to] == -1 && f[v][to] < c[v][to]) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
	}
	return d[t] != -1;
}

long dfs (long v, long flow) {
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (long & to=ptr[v]; to<n; ++to) {
		if (d[to] != d[v] + 1)  continue;
		long pushed = dfs (to, min (flow, c[v][to] - f[v][to]));
		if (pushed) {
			f[v][to] += pushed;
			f[to][v] -= pushed;
			return pushed;
		}
	}
	return 0;
}

long dinic() {
	long flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, n * sizeof ptr[0]);
		while (long pushed = dfs (s, INF))
			flow += pushed;
	}
	return flow;
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    long x, y, z, m;
    scanf ("%ld%ld", &n, &m);
    s = 1; t = n++;
    for (int i = 1; i <= m; i++)
    {
        scanf ("%ld%ld%ld", &x, &y, &z);
        c[x][y] = z;
    }

    cout << dinic();


    return 0;
}

