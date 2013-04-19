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

char ac[4];
Int ans = (1ll << 60);
void go(vector<Int> a, int p) {
	if (a.size() == 1) {
		if (a[0] < ans)
			ans = a[0];
		return ;
	}
	sort(a.begin(), a.end());
	do {
		vector<Int>b = a;
		Int x = b.back(); b.pop_back();
		Int y = b.back(); b.pop_back();
		if (ac[p] == '+')
			b.push_back(x + y);
		else b.push_back(x * y);
		go(b, p + 1);
	}while(next_permutation(a.begin(), a.end()));
}

int main() {
	vector <Int> a(4);
	for (int i = 0; i < 4; i++)
		cin >> a[i];
	for (int i = 0; i < 3; i++)
		cin >> ac[i];
	go(a, 0);
	cout << ans;
	return 0;
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Jul 10, 2011 4:55:33 AM
// contest: 55
// link: /contest/55/submission/540188
// time: 30 ms
// verdict: Accepted
// problem: 55B - Smallest number
// ID: 540188
// downloaded by very stupid script
