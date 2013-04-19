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

int c[10], k, n, ans = 2;
int main() {
	cin >> k >> n;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		c[x/1000]++;
	}

	for (int i = 0; i < 10; i++)
		ans += (c[i] + k - 1) / k;

	cout << ans << endl;
	return 0;
}
