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

unsigned long long s, a, n, x, i;

int main() {
	cin >> n;
	x = 1;
	for (i = 1; i <= n; i++) {
		cin >> a; a--;
		s += i * a;
	}
	cout << n + s;

	return 0;
}




// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Aug 7, 2011 3:07:25 PM
// contest: 103
// link: /contest/103/submission/589709
// time: 10 ms
// verdict: Accepted
// problem: 103A - Testing Pants for Sadness
// ID: 589709
// downloaded by very stupid script
