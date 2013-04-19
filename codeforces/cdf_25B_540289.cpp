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
#define pb push_back

string s;
int n;
int main() {
	cin >> n >> s;
	if (n < 4)
		cout << s;
	else {
		int k = (n&1) ? n - 3 : n - 2;
		for (int i = 0; i < k; i += 2)
			cout << s[i] << s[i + 1] << "-";
		for (int i = k; i < n; i++)
			cout << s[i];
	}
	return 0;
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Jul 10, 2011 7:25:16 AM
// contest: 25
// link: /contest/25/submission/540289
// time: 30 ms
// verdict: Accepted
// problem: 25B - Phone numbers
// ID: 540289
// downloaded by very stupid script
