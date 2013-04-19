#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

typedef long long Int;
#define sz(x) ((int)x.size())
#define pb push_back
#define forc(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); ++i)
#define all(x) x.begin(),x.end()

map<string,int>c;
string s;
vector<int>a, b;
int n, m, mn = (1 << 30), mx = 0;

int main() {
	cin >> n >> m;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++) {
		cin >> s; c[s]++;
	}
	forc(i,c)b.pb(i->second);
	sort(all(a)); sort(all(b));
	int s = 0;
	for (int i = 0; i < b.size(); i++)
		s += a[i] * b[i];
	mx = max(mx, s);
	mn = min(mn, s);
	s = 0;
	reverse(all(a));reverse(all(b));
	for (int i = 0; i < b.size(); i++)
		s += a[i] * b[i];
	mx = max(mx, s);
	mn = min(mn, s);
	s = 0;
	reverse(all(b));
	for (int i = 0; i < b.size(); i++)
		s += a[i] * b[i];
	mx = max(mx, s);
	mn = min(mn, s);
	s = 0;
	reverse(all(a));reverse(all(b));
	for (int i = 0; i < b.size(); i++)
		s += a[i] * b[i];
	mx = max(mx, s);
	mn = min(mn, s);
	cout << mn << " " << mx;
	return 0;
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Jul 10, 2011 8:31:23 AM
// contest: 12
// link: /contest/12/submission/540346
// time: 30 ms
// verdict: Accepted
// problem: 12C - Fruits
// ID: 540346
// downloaded by very stupid script
