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

typedef vector<char> vb;
vector<vb>A, B, tr;
vector<int>err;
vb cur;
string s;
int n, m;

void go (int v, int k) {
	if (v == n) {
		if (!k)
			A.pb(cur);
		return ;
	}
	if (!k) {
		cur[v] = tr[0][v] ^ 1;
		go(v + 1, k);
		return ;
	}
	if (n - v == k) {
		cur[v] = tr[0][v];
		go(v + 1, k - 1);
		return ;
	}
	cur[v] = tr[0][v];
	go(v + 1, k - 1);
	cur[v] = tr[0][v] ^ 1;
	go(v + 1, k);
}

void tran(vb v, int k) {
	for (int i = 0; i < A.size(); i++) {
		cur = A[i];
		int cnt = 0;
		for (int j = 0; j < n; j++)
			if (cur[j] == v[j])
				cnt++;
		if (cnt == k)
			B.pb(cur);
	}
	A = B; B.clear();
}

int main() {
	cin >> n >> m;
	tr.resize(m); err.resize(m);
	cur.resize(n);
	for (int i = 0; i < m; i++) {
		cin >> s >> err[i];
		for (int j = 0; j < sz(s); j++)
			tr[i].pb(s[j] == '0');
	}
	go(0, err[0]);
	for (int i = 1; i < m; i++)
		tran(tr[i], err[i]);
	cout << A.size() << endl;
	return 0;
}





// lang: GNU C++
// memory: 35300 KB
// author: imslavko
// submit_date: Jul 10, 2011 12:23:49 PM
// contest: 47
// link: /contest/47/submission/540576
// time: 810 ms
// verdict: Accepted
// problem: 47D - Safe
// ID: 540576
// downloaded by very stupid script
