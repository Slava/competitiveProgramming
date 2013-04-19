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

string s;
int k, n, alpha[256];

int main() {
	cin >> k >> s;
	n = (int)s.size();
	if (n % k != 0)
		return cout << -1 << endl, 0;

	for (int i = 0; i < n; i++)
		alpha[s[i]]++;

	string t;
	for (int i = 0; i < 256; i++)
		t += string(alpha[i]/k, i);
		

	if (t.size() * k != n)
		return cout << -1 << endl, 0;

	for (int i = 0; i < k; i++)
		cout << t;
	cout << endl;

	return 0;
}




// lang: GNU C++
// memory: 1500 KB
// author: imslavko
// submit_date: Aug 27, 2012 7:38:53 PM
// contest: 219
// link: /contest/219/submission/2053240
// time: 30 ms
// verdict: Accepted
// problem: 219A - k-String
// ID: 2053240
// downloaded by very stupid script
