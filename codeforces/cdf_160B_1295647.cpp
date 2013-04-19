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



void solve() {
	string s; 
	int n;
	cin >> n >> s;
	sort(s.begin(), s.begin()+n);
	sort(s.begin()+n, s.end());
	bool less = 1, greater = 1;
	for (int i = 0, j = n; i < n; i++, j++) {
		less &= s[i] < s[j];
		greater &= s[i] > s[j];
	}

	if (less | greater)
		cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	solve();
	return 0;
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Mar 6, 2012 7:10:08 PM
// contest: 160
// link: /contest/160/submission/1295647
// time: 30 ms
// verdict: Accepted
// problem: 160B - Unlucky Ticket
// ID: 1295647
// downloaded by very stupid script
