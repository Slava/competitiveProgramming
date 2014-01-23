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

#include <cmath>
#include <cstring>

using namespace std; 


#define isNumber(x) (x>='0'&&x<='9')
#define isAlpha(x) ((x>='a'&&x<='z')||(x>='A'&&x<='Z'))


long long INF = (1e12+10);
const int N = 100100;
string s;
int n, k, st[N], fn[N], nodes, coef[N], which[N];
long long cnt[N][26], answer[26];

void inc(long long &a, long long b, long long c = 1) {
	int logSum = (int)((log10(c * 1.) + log10(b * 1.)));
	if (logSum >= 16)
		a = INF;
	else if (a + b * c >= (long long)(1e16))
		a = INF;
	else a += b * c;
}

void solve() {
#ifndef imslavko
	freopen("az.in", "r", stdin);
	freopen("az.out", "w", stdout);
#endif

	cin >> s >> k;
	s = "1(" + s + ")";
	n = (int)s.size();
	vector<int> stack;
	for (int i = 0, c = 0; i < n; i++) {
		if (s[i] == '(') {
			st[nodes] = i;
			coef[nodes] = c;
			c = 0;
			which[i] = nodes;
			stack.push_back(nodes++);
		} else if (s[i] == ')') {
			fn[stack.back()] = i;
			stack.pop_back();
		} else if (isNumber(s[i])) {
			c = c * 10 + s[i] - '0';
		}
	}

	for (int i = nodes-1; i >= 0; i--) {
		for (int j = st[i] + 1; j < fn[i]; j++)
			if (isAlpha(s[j]))
				inc(cnt[i][s[j]-'a'],1);
			else if (s[j] == '(') {
				for (int k = 0; k < 26; k++)
					inc(cnt[i][k], cnt[which[j]][k], coef[which[j]]);
				j = fn[which[j]];
			}
	}
	
	for (int i = 0; i < n && k > 0; i++) {
		if (isAlpha(s[i])) {
			inc(answer[s[i]-'a'],1);
			if (s[i] == 'a')
				k--;
		}
		else if (s[i] == '(') {
			int wh = which[i];
			long long iter = min((long long)coef[wh], (cnt[wh][0] ? k / cnt[wh][0] : INF));
			if (iter == coef[wh] || iter * cnt[wh][0] >= k)
				iter--;
			if (cnt[wh][0] == -1)
				iter = 0;

			for (int j = 0; j < 26; j++)
				inc(answer[j],cnt[wh][j],iter);
			k -= iter * cnt[wh][0];
		}
	}

	for (int i = 0; i < 26; i++)
		if (answer[i])
			cout << (char)('a'+i) << " " << (answer[i] > (long long)(1e12) ? -1 : answer[i]) << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	solve();
	return 0;
}

