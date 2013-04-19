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
#include <sstream>

using namespace std; 

#ifdef WIN32
#define i64 "%I64d"
#else
#define i64 "%l""ld"
#endif

typedef long long ll;

bool inp = 1;
int in() { int x; inp &= scanf("%d", &x) == 1; return x; } 
long long inL() { long long x; inp &= scanf(i64, &x) == 1; return x; }
string s;

int main() {
	cin >> s;
	int n = (int)s.size();
	long long mx = -1;

	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			if (i > 7 || j-i > 7 || n-j > 7 || n-j < 1 || j-i < 1 || i < 1)
				continue;
			stringstream in;
			in << s.substr(0,i) << " " << s.substr(i, j-i) << " " << s.substr(j, n-j);
			long long fi, se, th, L = 1000000;
			in >> fi >> se >> th;
			if (fi > L || se > L || th > L)
				continue;
			stringstream out;
			out << fi << se << th;
			if (out.str().size() != s.size()) {
				continue;
			}
			mx = max(mx, fi+se+th);
		}
	}

	cout << mx << endl;

	return 0;
}




// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Apr 14, 2012 12:11:39 PM
// contest: 175
// link: /contest/175/submission/1532206
// time: 50 ms
// verdict: Accepted
// problem: 175A - Robot Bicorn Attack
// ID: 1532206
// downloaded by very stupid script
