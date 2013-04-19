#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

long long n, sum, x, mn = (1ll << 62);
int main() {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		sum += x;
		if (x < mn)
			mn = x;
	}
	cout << sum - mn;

	return 0;
}


