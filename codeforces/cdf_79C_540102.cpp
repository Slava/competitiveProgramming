#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long Int;

#define f first
#define s second
#define pb push_back
#define sz(x) ((int)x.size())
typedef pair<int,int> ii;

string s, w[10];

vector<ii>a;
vector<int> col;
int n, ccol;
int pos, len;

bool solve (int ln) {
	col.assign(ccol, 0);
	int i = 0, j = 0, j1 = 0, cnt = 0, l = 0;
	for (; i < ln; i++)
		for (; j < sz(a) && a[j].f == i; j++) {
			col[a[j].s]++;
			if (col[a[j].s] == 2)
				cnt++;
		}
	if (!cnt) {
		pos = 0; len = ln; return true;
	}
	for (; i < sz(s); i++, l++) {
		for (; j1 < sz(a) && a[j1].f == l; j1++) {
			col[a[j1].s]--;
			if (col[a[j1].s] == 1)
				cnt--;
		}
		for (; j < sz(a) && a[j].f == i; j++) {
			col[a[j].s]++;
			if (col[a[j].s] == 2)
				cnt++;
		}
		if (!cnt) {
			pos = l + 1; len = ln; return true;
		}
	}
	return false;
}

int main() {
	cin >> s >> n;
	for (int i = 0; i < n; i++)
		cin >> w[i];
	for (int i = 0; i < sz(s); i++)
		for (int j = 0; j < n; j++)
			if (i + sz(w[j]) <= sz(s) && s.substr(i, sz(w[j])) == w[j]) {
				a.pb(ii( i, ccol ));
				a.pb(ii( i + sz(w[j]) - 1, ccol ));
				ccol++;
			}
	sort(a.begin(), a.end());
	int l = 1, r = sz(s), m;
	while (l <= r) {
		m = (l + r) / 2;
		if (solve(m))
			l = m + 1;
		else r = m - 1;
	}
	cout << len << " " << pos << endl;
	return 0;
}





// lang: GNU C++
// memory: 26200 KB
// author: imslavko
// submit_date: Jul 10, 2011 2:16:27 AM
// contest: 79
// link: /contest/79/submission/540102
// time: 1000 ms
// verdict: Accepted
// problem: 79C - Beaver
// ID: 540102
// downloaded by very stupid script
