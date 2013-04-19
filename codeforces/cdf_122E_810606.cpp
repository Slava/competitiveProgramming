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

vector<long long> lucky, f;
vector<int> u;
long long n, k;


void dfs(long long v) {
	if (v > 7777777777LL)
		return;
	if (v) lucky.push_back(v);
	dfs(v * 10 + 4);
	dfs(v * 10 + 7);
}

int main() {
	dfs(0);
	sort (lucky.begin(), lucky.end());
	f.push_back(1);

	cin >> n >> k;

	for (int i = 2; i <= n; i++) {
		if (f.back() >= k) break;
		f.push_back(f.back() * i);
	}

	if (f.size() == n && k > f.back()) {
		puts("-1");
		return 0;
	}

	int cnt = 0;
	for (int i = 0; i < (int)lucky.size(); i++)
		if (lucky[i] > n - (int)f.size())
			break;
		else cnt++;
	
	u.resize(f.size());
	reverse(f.begin(), f.end());
	f.push_back(2000);

	k--;
	for (int i = 0; i < (int)u.size(); i++) {
		int c = 0, a;
		while (k >= f[i + 1]) {
			k -= f[i + 1];
			c++;
		}

		for (int j = 0; j < (int)u.size(); j++)
			if (!u[j])
				if (c)c--;
				else {
					a = j;
					u[j] = 1;
					break;
				}
		a += n - (int)u.size() + 1;
		int j = i + n - (int)u.size() + 1;
		if (binary_search (lucky.begin(), lucky.end(), a) &&
			binary_search (lucky.begin(), lucky.end(), j))
			cnt++;
	}

	cout << cnt << endl;

	return 0;
}




// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Oct 28, 2011 8:30:43 AM
// contest: 122
// link: /contest/122/submission/810606
// time: 30 ms
// verdict: Accepted
// problem: 122E - Lucky Permutation
// ID: 810606
// downloaded by very stupid script
