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

#define sqr(x) (x)*(x)

const int N = 220;
double a[N][N], d[N], inf = 1e9, x[N], y[N], metro, pesh;
int n, v, _, __, u[N], from[N];
vector<int> l;

double dist(int i, int j) {
	return sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j]));
}

int main() {
	scanf("%lf%lf", &pesh, &metro);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lf%lf", x + i, y + i);
	for (; scanf("%d%d", &_, &__) == 2 && _ && __; )
		a[_][__] = a[__][_] = dist(_, __) / metro;
	n++; scanf("%lf%lf%lf%lf", x, y, x + n, y + n); n++;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!a[i][j])
				a[i][j] = dist(i, j) / pesh;
	for (int i = 1; i < n; i++)
		d[i] = inf;
	for (int i = 0; i < n; i++) {
		v = -1;
		for (int j = 0; j < n; j++)
			if (!u[j] && (v == -1 || d[v] > d[j]))
				v = j;
		u[v] = 1;
		for (int j = 0; j < n; j++)
			if (d[j] > d[v] + a[v][j]) {
				d[j] = d[v] + a[v][j];
				from[j] = v;
			}
	}
	printf("%.7lf\n", d[n - 1]);
	for (v = from[n - 1]; v; v = from[v])
		l.push_back(v);
	reverse (l.begin(), l.end());
	printf("%d ", l.size());
	for (int i = 0; i < l.size(); i++)
		printf("%d ", l[i]);
	return 0;
}
