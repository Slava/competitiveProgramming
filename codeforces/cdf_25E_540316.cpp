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

string doit(string s, string t) {
	string r = t + "$" + s;
	vector<int>p(r.size(), 0);
	int j = 0;
	for (int i = 1; i < sz(r); i++) {
		while (j > 0 && r[j] != r[i])
			j = p[j - 1];
		if (r[j] == r[i])
			j++;
		p[i] = j;
	}
	int mx = 0;
	for (int i = 0; i < sz(r); i++)
		mx = max(mx, p[i]);
	if (mx == sz(t))
		return s;
	return s + t.substr(p[sz(r) - 1]);
}

string s[3];
int main() {
	int ans = (1 << 30);
	for (int i = 0; i < 3; i++)
		cin >> s[i];
	sort(s, s + 3);
	do {
		string r = doit(doit(s[0], s[1]), s[2]),
			   d =doit(s[0], doit(s[1], s[2]));
		ans = min(ans, min(sz(r), sz(d)));
	}while(next_permutation(s, s + 3));
	cout << ans;
	return 0;
}





// lang: GNU C++
// memory: 4600 KB
// author: imslavko
// submit_date: Jul 10, 2011 8:07:18 AM
// contest: 25
// link: /contest/25/submission/540316
// time: 160 ms
// verdict: Accepted
// problem: 25E - Test
// ID: 540316
// downloaded by very stupid script
