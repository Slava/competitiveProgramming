#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long Int;
#define sz(x) ((int)x.size())
#define pb push_back

int n, p[1010], a[1010], b[1010], c[1010], d[1010], k;
int get(int x) {
	if (p[x] != x)
		p[x] = get(p[x]);
	return p[x];
}

void unite(int x, int y) {
	x = get(x); y = get(y);
	if (rand() & 1)
		p[x] = y;
	else p[y] = x;
}

int main() {
	for (int i = 1; i < 1010; i++)
		p[i] = i;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (get(x) != get(y))
			unite(x, y);
		else {
			a[k] = x; b[k] = y; k++;
		}
	}
	k = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (get(i) != get(j)) {
				c[k] = i; d[k] = j; k++;
				unite(i,j);
			}
	cout << k << endl;
	for (int i = 0; i < k; i++)
		cout << a[i] << " " << b[i] << " " << c[i] << " " << d[i] << "\n";
	return 0;
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Jul 10, 2011 7:35:07 AM
// contest: 25
// link: /contest/25/submission/540297
// time: 60 ms
// verdict: Accepted
// problem: 25D - Roads not only in Berland
// ID: 540297
// downloaded by very stupid script
