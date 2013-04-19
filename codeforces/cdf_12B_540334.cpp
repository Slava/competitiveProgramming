#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long Int;
#define sz(x) ((int)x.size())
#define pb push_back

string s, t;
int main() {
	cin >> s >> t;
	sort(s.begin(), s.end());
	if (s[0] == '0')
		for (int i = 1; i < sz(s); i++)
			if (s[i] != '0') {
				swap(s[i], s[0]);
				break;
			}
	if (s == t)
		puts("OK");
	else puts("WRONG_ANSWER");
	return 0;
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Jul 10, 2011 8:21:28 AM
// contest: 12
// link: /contest/12/submission/540334
// time: 30 ms
// verdict: Accepted
// problem: 12B - Correct Solution?
// ID: 540334
// downloaded by very stupid script
