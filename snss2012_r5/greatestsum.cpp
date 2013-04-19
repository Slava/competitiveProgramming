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

int a, b, p, k, mx, l, r, sum, start = -1;

int f(int x) {
	return (a*abs(x)+b)%p * (x>0?-1:1);
}

int main() {
	if (fopen("greatestsum.in", "r")) {
		freopen("greatestsum.in", "r", stdin);
		freopen("greatestsum.out", "w", stdout);
	}

	ios_base::sync_with_stdio(0);

	cin >> a >> b >> p >> k;
	
	l = -1; r = -1;
	mx = -(1<<30);

	for (int i = 0; i < 100000; i++) {
		//cerr << k << endl;
		sum += k;

		if (sum > mx) {
			mx = sum;
			l = start+1;
			r = i;
		}

		if (sum < 0) {
			sum = 0;
			start = i;
		}
		k = f(k);
	}

	if (r-l > 10000)
		cout << "Infinite" << endl;
	else
		cout << mx << endl;
	return 0;
}
