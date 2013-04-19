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

string s;
map<string, long long> M;
map<long long, long long> C;
int n;
long long sum, ps;
#define foreach(i,c) for(typeof(c.begin()) i = c.begin(); i != c.end(); ++i)

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> s >> x;
		M[s] = max(M[s], x);
	}

	foreach(i,M) {
		C[i->second]++;
	}

	foreach(i,C) {
		i->second += ps;
		ps = i->second;
	}

	cout << M.size() << endl;
	foreach(i,M) {
		cout << i->first << " ";
		long long better = (M.size()-C[i->second]),
			   worse = C[i->second], CC = M.size();
		if (better*100 > 50*CC)
			cout << "noob";
		else if (worse*100 >= 50*CC && better*100 > 20*CC)
			cout << "random";
		else if (worse*100 >= 80*CC && better*100 > 10*CC)
			cout << "average";
		else if (worse*100 >= 90*CC && better*100 > 1*CC)
			cout << "hardcore";
		else 
			cout << "pro";
		cout << endl;
	}

	return 0;
}





// lang: GNU C++
// memory: 1500 KB
// author: imslavko
// submit_date: Apr 14, 2012 12:38:41 PM
// contest: 175
// link: /contest/175/submission/1533602
// time: 30 ms
// verdict: Accepted
// problem: 175B - Plane of Tanks: Pro
// ID: 1533602
// downloaded by very stupid script
