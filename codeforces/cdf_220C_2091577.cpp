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

#define abs(x) (x<0?-(x):x)
#define mp make_pair

int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n), b(n), pos(n);
	for (int i = 0; i < n; i++)
		cin >> a[i], a[i]--;
	for (int i = 0; i < n; i++)
		cin >> b[i], b[i]--;
	for (int i = 0; i < n; i++)
		pos[a[i]] = i;

	set<pair<int,int> > s1, s2;

	for (int i = 0; i < n; i++) {
		int d = abs(i-pos[b[i]]);
		if (i <= pos[b[i]])
			s1.insert(mp(d,i));
		else
			s2.insert(mp(d,i));
	}

	int pl1 = 0, pl2 = 0;
	for (int i = 0; i < n; i++) {
		int res = 1<<30;
		if (!s1.empty())
			res = min(res, s1.begin()->first + pl1);
		if (!s2.empty())
			res = min(res, s2.begin()->first + pl2);
		cout << res << "\n";
		pl1++; pl2--;

		// move with distance 0
		while (!s2.empty() && s2.begin()->first+pl2 == 0) {
			int j = s2.begin()->second;
			s2.erase(s2.begin());
			s1.insert(mp(-pl1,j));
		}

		// move i-th to end
		s1.erase(mp(pos[b[i]]-pl1+1,i));
		
		if (pos[b[i]] == n-1)
			s1.insert(mp(-pl1,i));
		else 
			s2.insert(mp(n-1-pos[b[i]]-pl2,i));

	}

	return 0;
}
