#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <bitset>

#include <cmath>
#include <cstring>

using namespace std; 


template <class T>
void sortUnique(T &a) {
	sort(a.begin(),a.end());
	a.resize(unique(a.begin(),a.end())-a.begin());
}

template <class T>
void sortUnique(T a, int n) {
	sort(a,a+n);
	n = unique(a,a+n) - a;
}


void solve() {
	long long k, n;
	cin >> n >> k; k--;
	vector<long long> a(n), b, c;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	b = a;
	sortUnique(b);
	sort(a.begin(), a.end());

	c.resize(b.size());
	for (int i = 0; i < (int)b.size(); i++)
		c[i] = upper_bound(a.begin(),a.end(),b[i]) - lower_bound(a.begin(),a.end(),b[i]);
	for (int i = 0; i < (int)b.size(); i++) {
		if (c[i] * 1LL * n <= k) {
			k -= c[i] * 1LL * n;
		} else {
			cout << b[i] << " ";
			for (int j = 0; j < (int)b.size(); j++) {
				if (k >= c[j]*1LL*c[i])
					k -= c[j]*1LL*c[i];
				else {
					cout << b[j] << "\n";
					break;
				}
			}
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	solve();
	return 0;
}





// lang: GNU C++
// memory: 3700 KB
// author: imslavko
// submit_date: Mar 6, 2012 7:48:31 PM
// contest: 160
// link: /contest/160/submission/1299982
// time: 110 ms
// verdict: Accepted
// problem: 160C - Find Pair
// ID: 1299982
// downloaded by very stupid script
