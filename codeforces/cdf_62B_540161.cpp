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

string s;
string w;
typedef pair<char,int> ci;
ci A[101010];
Int ans;
int n, k;

int main() {
	cin >> n >> k;
	cin >> w;
	for (int i = 0; i < sz(w); i++)
		A[i] = ci(w[i], i);
	sort(A, A + k);
	for (int z = 0; z < n; z++) {
		cin >> s;
		ans = 0;
		for (int i = 0; i < sz(s); i++) {
			int p = lower_bound(A, A + k, ci(s[i], i)) - A;
			p = max(0, p - 1);
			Int pl = (1ll << 60);
			for (int j = p; j <= min(k - 1, p + 1); j++)
				if (A[j].first == s[i] && pl > abs(A[j].second - i))
					pl = abs(A[j].second - i);
			if (pl == (1ll << 60))
				pl = sz(s);
			ans += pl;
//			cout << "+ " << pl << endl;
		}
		cout << ans << endl;
	}
	return 0;
}





// lang: GNU C++
// memory: 2600 KB
// author: imslavko
// submit_date: Jul 10, 2011 3:47:45 AM
// contest: 62
// link: /contest/62/submission/540161
// time: 160 ms
// verdict: Accepted
// problem: 62B - Tyndex.Brome
// ID: 540161
// downloaded by very stupid script
