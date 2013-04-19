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

string s[50009], S, wh = "22233344115566070778889990!";
int n, dp[109], to[109];

bool ok(int st, int ii) {
	string T = S.substr(st, S.size() - st);
	if (s[ii].size() > T.size())return 0;
	for (int i = 0; i < s[ii].size(); i++)
		if (T[i] != wh[s[ii][i] - 'a'])
			return 0;
	return 1;
}
int go(int st) {
	if (st == S.size())
		return 0;
	if (dp[st] != -1)
		return dp[st];
	int &res = dp[st], t;
	res = (1 << 30);
	for (int i = 0; i < n; i++) {
		if (!ok(st, i))continue;
		t = go(st + s[i].size());
		if (t < 0) continue;
		if (res > t + 1) {
			res = t + 1;
			to[st] = i;
		}
	}
	return res;
}

void out(int st) {
	if (to[st] < 0) {
		cout << "No solution.";
		return;
	}
	cout << s[to[st]] << " ";
	if (st + s[to[st]].size() != S.size())
		out(st + s[to[st]].size());
}

int main() {
	while (cin >> S && S != "-1") {
		cin >> n;
		memset(dp, ~0, sizeof dp);
		memset(to, ~0, sizeof to);
		for (int i = 0; i < n; i++)
			cin >> s[i];
		int st, ans = go(0);
		out(0); 
		cout << "\n";
	}
	return 0;
}
