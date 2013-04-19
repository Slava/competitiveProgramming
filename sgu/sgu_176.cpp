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
#include <cassert>

using namespace std;

const int N = 200;
#define int long long
int c[N][N],
    f[N][N], limit,
    n, m, source, sink,
	from[N], inf = 1LL << 62,
	q[N*N], h, t, sumneeded,
	lmt[N*N], ea[N*N], eb[N*N];

int in() {
	int x;
	scanf("%I64d", &x);
	return x;
}

int maxflow() {
    memset(f, 0, sizeof f);
	for (;;) {
        h = t = 0;
        for (int i = 0; i < n; i++)
            from[i] = -1;
        from[source] = source;
        q[t++] = source;
        for (int cur; h < t; h++) {
            cur = q[h];
            for (int v = 0; v < n; v++) {
                if (from[v] == -1 && (c[cur][v]-f[cur][v]) > 0) {
                    q[t++] = v;
                    from[v] = cur;
                }
            }
        }

        if (from[sink] == -1)   
            break;
        int cf = inf;

        for (int cur = sink; cur != source;) {
            int prev = from[cur];
            cf = min (cf, c[prev][cur] - f[prev][cur]);
            cur = prev;
        }
        for (int cur = sink; cur != source;) {
            int prev = from[cur];
            f[prev][cur] += cf;
            f[cur][prev] -= cf;
            cur = prev;
        }
    }

    int flow = 0;
    for (int i = 0; i < n; i++)
        if (c[source][i])
            flow += f[source][i];
	return flow;
}

bool ok(int F) {
	c[n-3][0] = F;
	return maxflow() == sumneeded;
}

#undef int
int main() {
#define int long long
	n = in(); m = in();


	source = n;
	sink = n+1;
	n += 2;

	for (int i = 0; i < m; i++) {
		int a, b, z, cc;
//		scanf("%d%d%d%d", &a, &b, &z, &cc);
		a = in(); b = in(); z = in(); cc = in();
		a--; b--;
		ea[i] = a; eb[i] = b;
		if (cc) {
			c[source][b] += z;
			c[a][sink] += z;
			sumneeded += z;
			lmt[i] = z;
		} else {
			c[a][b] += z;
		}

		if (!a) limit += z;
	}

	c[n-3][0] = inf;
	if (maxflow() != sumneeded) {
		puts("Impossible");
		return 0;
	}
	int l = 0, r = limit, mid;
	while (l <= r) {
		mid = (l+r) / 2;
		if (ok(mid))
			r = mid-1;
		else
			l = mid+1;
	}

	if (ok(r+1)) {
		c[n-3][0] = r+1;
		maxflow();
		printf("%I64d\n", r+1);
		for (int i = 0; i < m; i++) {
			printf("%I64d ", f[ea[i]][eb[i]]+lmt[i]);
		}
	} 	
	return 0;
}
