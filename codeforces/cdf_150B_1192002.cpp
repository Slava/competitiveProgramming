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


	long long mod = 1000000007;
	long long power(long long a, int n) {
		long long res = 1;
		while (n > 0) {
			if (n & 1)
				res = (a * res) % mod;
			a = (a * a) % mod;
			n >>= 1;
		}
		return res;
	}
int n, m, k;
int main() {
	cin >> n >> m >> k;
	long long res = 0;

	if (n < k)
		res = power(m, n);
	else if (k == 1)
		res = power(m, n);
	else if (k == n) {
		if (k % 2 == 0)
			res = power(m, n/2);
		else res = power(m, n/2+1);
	}
	else if (k % 2 == 0)
		res = m;
	else if (k % 2 == 1)
		res = (m>1?m*1LL*(m-1):0)+m;
	cout << res % mod;
	return 0;
}




// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Feb 17, 2012 7:57:14 PM
// contest: 150
// link: /contest/150/submission/1192002
// time: 50 ms
// verdict: Accepted
// problem: 150B - Quantity of Strings
// ID: 1192002
// downloaded by very stupid script
