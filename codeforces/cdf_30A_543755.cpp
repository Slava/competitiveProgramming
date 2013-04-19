//#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <fstream>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long Int;
typedef pair<int,int> ii;
#define sz(x) ((int)x.size())
#define pb push_back
#define forc(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); ++i)
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)

char s[400];
Int a, b, n, x, y;
int main() {
	cin >> a >> b >> n;
	for (x = -10000; x < 10001; x++) {
		sprintf(s, "%I64d", x);
		if (strlen(s) * (x == 1 || x == -1 ? 1 : n) > 10)
			continue;
		y = 1;
		for (int i = 0; i < n; i++)
			y *= x;
		if (a * y == b) {
			cout << x << endl;
			return 0;
		}
	}
	cout << "No solution\n";
	return 0;
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Jul 13, 2011 2:47:01 AM
// contest: 30
// link: /contest/30/submission/543755
// time: 30 ms
// verdict: Accepted
// problem: 30A - Accounting
// ID: 543755
// downloaded by very stupid script
