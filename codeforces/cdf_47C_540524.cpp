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

string s[6];
char was;
vector<string>best;

void check() {
	vector<string>a;
	int A = sz(s[0]) - 1, B = sz(s[3]) - 1, C = sz(s[1]) - 1, D = sz(s[4]) - 1;
	if (s[0][0] != s[3][0] || s[0][A] != s[4][0] ||
		s[3][B] != s[1][0] || s[4][B] != s[1][A] ||
		s[5][0] != s[1][C] || s[4][D] != s[2][0] ||
		s[2][s[2].size() - 1] != s[5][s[5].size() - 1]) return;
	a.assign(sz(s[4]), string(sz(s[1]), '.'));
	for (int i = 0; i < sz(s[0]); i++)
		a[0][i] = s[0][i];
	for (int i = 0; i < sz(s[1]); i++)
		a[B][i] = s[1][i];
	for (int i = 0; i < sz(s[2]); i++)
		a[D][A + i] = s[2][i];
	for (int i = 0; i < sz(s[3]); i++)
		a[i][0] = s[3][i];
	for (int i = 0; i < sz(s[4]); i++)
		a[i][A] = s[4][i];
	for (int i = 0; i < sz(s[5]); i++)
		a[B + i][C] = s[5][i];
	was = 1;
	if (best.empty() || best > a)
		best = a;
}

int main() {
	for (int i = 0; i < 6; i++)
		cin >> s[i];
	sort(s, s + 6);
	do {
		if (sz(s[0]) + sz(s[2]) - 1 == sz(s[1]) &&
			sz(s[3]) + sz(s[5]) - 1 == sz(s[4]))
			check();
	}while (next_permutation(s, s + 6));
	if (was) {
		for (int i = 0; i < sz(best); i++)
			cout << best[i] << endl;
	}
	else printf("Impossible");
	return 0;

}







// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Jul 10, 2011 11:21:35 AM
// contest: 47
// link: /contest/47/submission/540524
// time: 30 ms
// verdict: Accepted
// problem: 47C - Crossword
// ID: 540524
// downloaded by very stupid script
