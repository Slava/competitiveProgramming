#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

#define f first
#define s second
pair<int, pair<int,int> >e[100 * 100];
int n, m, D, A, a[110][110], p[110], b[110][110];
char c;
long long s;

int find(int x) {
	if (p[x] != x)
		p[x] = find(p[x]);
	return p[x];
}

void unite(int x, int y) {
	if (rand() & 1)
		p[x] = y;
	else p[y] = x;
}

int main() {
	cin >> n >> D >> A;
	for (int i = 0; i < n; i++)
		p[i] = i;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> c;
			a[i][j] = c - '0';
			if (i >= j)
				continue;
			if (c == '1') {
				s += D;
				e[m].f = -D;
			}
			else 
				e[m].f = A;
			e[m].s.f = i;
			e[m].s.s = j;
			m++;
		}
	sort (e, e + m);
	for (int i = 0; i < m; i++) {
		int x = find(e[i].s.s),
			y = find(e[i].s.f);
		if (x != y) {
			unite(x, y);
			s += e[i].f;
			b[e[i].s.s][e[i].s.f] =
			b[e[i].s.f][e[i].s.s] = 1;
		}
	}
	cout << s << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (a[i][j] == b[i][j])
				printf("0");
			else if (a[i][j] && !b[i][j])
				printf("d");
			else if (!a[i][j] && b[i][j])
			   printf("a");
		printf("\n");
	}
	return 0;
}
