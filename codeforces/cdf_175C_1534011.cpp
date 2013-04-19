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

typedef long long i64;
typedef pair<i64,i64> ii;
vector<ii> a;

int n, t;
i64 p[200];

int main() {
	cin >> n; 
	for (int i = 0; i < n; i++) {
		ii pa;
		cin >> pa.second >> pa.first;
		a.push_back(pa);
	}

	sort(a.begin(), a.end());
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> p[i];
	}
	p[t] = 1000000000000000LL;

	long long killed = 0, sum = 0;
	for (int i = 0, j = 0; i < n;) {
		if (killed >= p[j])
			j++;
		long long kill = min(a[i].second, p[j]-killed);
		sum += (j+1)*kill*a[i].first;
		a[i].second -= kill;
		killed += kill;

		if (!a[i].second)
			i++;
	}

	cout << sum << endl;

	return 0;
}




// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Apr 14, 2012 12:48:04 PM
// contest: 175
// link: /contest/175/submission/1534011
// time: 30 ms
// verdict: Accepted
// problem: 175C - Geometry Horse
// ID: 1534011
// downloaded by very stupid script
