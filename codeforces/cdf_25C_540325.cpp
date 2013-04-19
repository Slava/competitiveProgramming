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

#define int Int
int a[350][350], n, m;

 main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	cin >> m;
	for (int k = 0; k < m; k++) {
		int x, y, z, s = 0;
		cin >> x >> y >> z;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				s += (a[i][j] = min(a[i][j], min(a[i][x] + z + a[y][j],
												a[i][y] + z + a[x][j])));
		cout << s / 2 << " ";
	}
}






// lang: GNU C++
// memory: 2300 KB
// author: imslavko
// submit_date: Jul 10, 2011 8:13:45 AM
// contest: 25
// link: /contest/25/submission/540325
// time: 500 ms
// verdict: Accepted
// problem: 25C - Roads in Berland
// ID: 540325
// downloaded by very stupid script
