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

typedef long long i64;
#define long i64
typedef map<int,long>::iterator mit;
map<int,long> R;
long n, k, s, l, r, dl, dr;

int main() {
	cin >> n >> s >> k;
	R[s] = 0;

	for (int i = 0; i < k; i++) {
		cin >> l >> r;
		mit it = R.lower_bound(l);

		dl = dr = 1LL<<62;
		if (it != R.begin())
			it--;

		while (it != R.end() && it->first <= r) {
			dl = min(dl, it->second + abs(it->first-l+1));
			dr = min(dr, it->second + abs(it->first-r-1));
			mit prv = it;
			it++;
			if(l <= prv->first)
				R.erase(prv);
		}

		if (it != R.end()) {
			dl = min(dl, it->second + abs(it->first-l+1));
			dr = min(dr, it->second + abs(it->first-r-1));
		}

		if (l-1) R[l-1] = dl;
		if (r < n) R[r+1] = dr;
	}

	long ans = 1LL<<62;
	for (mit i = R.begin(); i != R.end(); ++i)
		ans = min(ans, i->second);

	cout << ans << endl;

	return 0;
}

