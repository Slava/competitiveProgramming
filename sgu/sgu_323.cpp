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

const int N = 2010;
const int M = 400100;
int p[N], r[N], st[N], sz, buy[M], bsz, maxSize = 1;
struct Edge {
	int x, y, cost, owner, id;
	Edge(){}
	Edge(int x, int y, int cost, int owner, int id) :
		x(x), y(y), cost(cost), owner(owner), id(id) {}
	bool operator < (const Edge b) const {
		return cost < b.cost;
	}
} e[M];

void init(int n) {
	for (int i = 0; i < n; i++) {
		p[i] = i; r[i] = 1;
	}
}

int get(int x) {
	if (p[x] == x)
		return x;
	sz = 0;
	st[sz++] = x;

	for (; p[x] != x; x = p[x])
		st[sz++] = x;
	while (sz > 0) {
		sz--;
		p[st[sz]] = x;
	}

	return x;
}

void unite(int x, int y) {
	x = get(x); y = get(y);
	if (r[x] > r[y]) {
		p[y] = x;
		r[x] += r[y];
	} else {
		p[x] = y;
		r[y] += x;
	}
}

int main() {
	int n, k, m, ans = 1<<30, mainComp = -1;
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 0; i < m; i++) {
		int x, y, p, c;
		scanf("%d%d%d%d", &x, &y, &p, &c);
		x--; y--;
		e[i*2] = Edge(x,y,c,p,i+1);
		e[i*2+1] = Edge(x,y,0,p,i+1);
	}

	m += m;
	sort(e, e+m);
	for (int comp = 1; comp <= k; comp++) {
		int sum = 0, size = 1;
		init(n);

		for (int i = 0; i < m; i++) {
			if (size == n)
				break;
			int x = e[i].x, y = e[i].y;
			if (e[i].cost == 0) {
				if (e[i].owner == comp && get(x) != get(y)) {
					unite(x,y);
					size++;
				}
				continue;
			}

			if (get(x) != get(y)) {
				unite(x,y);
				sum += e[i].cost;
				size++;
			}
		}

		if (sum < ans) {
			ans = sum;
			mainComp = comp;
		}

		maxSize &= size == n;
		if (!maxSize)
			break;
	}

	init(n);

	for (int i = 0; i < m; i++) {
		int x = e[i].x, y = e[i].y;
		if (e[i].cost == 0) {
			if (e[i].owner == mainComp && get(x) != get(y)) 
				unite(x,y);
			continue;
		}

		if (get(x) != get(y)) {
			unite(x,y);
			buy[bsz++] = e[i].id;
		}
	}
	printf("%d %d %d\n", ans, mainComp, bsz);
	for (int i = 0; i < bsz; i++)
		printf("%d\n", buy[i]);

	return 0;
}
