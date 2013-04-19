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

int a[101010], n, b[101010], k;

int main() {
	k = a[0] = -100;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], b[i] = a[i];
	sort(b,b+n);
	int l= -1, r=-1;
	for (int i = 0; i < n; i++)
		if (a[i] != b[i])
			if (l == -1)
				l = i;
			else r = i;
	if (l != -1 && r != -1)
		swap(a[l], a[r]);


	bool ok = 1;
	for (int i = 0; i <= n; i++)
		ok &= a[i] == b[i];
	if (ok)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}




// lang: GNU C++
// memory: 1600 KB
// author: imslavko
// submit_date: Aug 31, 2012 7:48:59 PM
// contest: 220
// link: /contest/220/submission/2074875
// time: 160 ms
// verdict: Accepted
// problem: 220A - Little Elephant and Problem
// ID: 2074875
// downloaded by very stupid script
