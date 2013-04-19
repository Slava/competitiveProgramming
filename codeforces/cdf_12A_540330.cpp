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

string s[3];

bool check() {
	return s[0][0] == s[2][2] && s[0][1] == s[2][1] && s[0][2] == s[2][0] && s[1][0] == s[1][2];
}

int main() {
	cin >> s[0] >> s[1] >> s[2];
	if (check())
		puts("YES");
	else puts("NO");
	return 0;
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Jul 10, 2011 8:18:56 AM
// contest: 12
// link: /contest/12/submission/540330
// time: 30 ms
// verdict: Accepted
// problem: 12A - Super Agent
// ID: 540330
// downloaded by very stupid script
