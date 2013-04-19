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

#define abs(x) (x<0?-(x):x)

int main() {
	ios_base::sync_with_stdio(0);
	if (fopen("goforwin.in", "r")) {
		freopen("goforwin.in", "r", stdin);
		freopen("goforwin.out", "w", stdout);
	}
	long long n, x, y;
	cin >> n >> x;
	y = n-x + x*2;
	n *= 2;
	x = __gcd(y,n);
	y /= x;
	n /= x;

	cout << y << "/" << n << endl;
	return 0;
}
