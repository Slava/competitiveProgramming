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

typedef long long Int;

#define mp make_pair
vector<pair<int,pair<pair<int,int>,pair<int,int> > > > ans;
set<Int> Set;
const int N = 500100;
int n, d[N];
bool u[N];
string s[N];
char S[N];
int LLL, RRR;

Int p[N], P = 1717;
vector<Int> Pr[N];

Int HashSub(vector<Int> &pr, int l, int r) {
	Int h = pr[r];
	if (l) h -= pr[l-1];
	return h * p[N-l-1];
}

int lcs(int I, int J ) {

	int l = 1, r = min(s[I].size(), s[J].size()), m;
	while (l <= r) {
		m = (l + r) / 2;
		bool ok = 0;
		Int hh;
		set<Int> Set;
		for (int i = 0; i + m <= (int)s[I].size(); i++)
			Set.insert(HashSub(Pr[I], i, i + m - 1));
		for (int i = 0; i + m <= (int)s[J].size(); i++)
			if (Set.find(HashSub(Pr[J], i, i + m - 1)) != Set.end()) {
				ok = 1; hh = HashSub(Pr[J], i, i + m - 1);
				RRR = i + 1;
				break;
			}
		if (ok) {
			l = m + 1;
			for (int i = 0; i + m <= (int)s[I].size(); i++)
				if (HashSub(Pr[I], i, i + m - 1) == hh) {
					LLL = i + 1;
					break;
				}
		}
		else r = m - 1;
	}
	return l-1;
}

int main() {
	freopen("mst.in", "r", stdin);
	freopen("mst.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", S);
		s[i] = S;
	}
	
	p[N-1] = 1;
	for (int i = N - 2; i >= 0; i--)
		p[i] = p[i+1] * P;
	for (int j = 0; j < n; j++) {
		Pr[j].resize(s[j].size());
		for (int i = 0; i < (int)s[j].size(); i++) {
			Pr[j][i] = s[j][i] * p[i];
			if (i)Pr[j][i]  += Pr[j][i-1];
		}
	}

	int w = 0;
	for (int i = 1; i < n; i++)
		d[i] = 1 << 30;

	for (int i = 1; i < n; i++) {
		int v = -1;
		for (int j = 0; j < n; j++)
			if (!u[j] && (v==-1 || d[v] > d[j]))
				v = j;
		if (v==-1||d[v] == 1<<30)
			break;
		u[v] = 1;
		for (int j = 0; j < n; j++)
			if (v != j) {
				int len = -lcs(v,j);
				if (d[j] > len) {
					d[j] = len;
					ans.push_back(mp(-len, mp(mp(v+1,j+1),mp(LLL,RRR))));
					w -= len;
				}
			}
	}

	printf("%d\n", w);
	for (int i = 0; i < (int)ans.size(); i++)
		printf("%d %d %d %d %d\n", ans[i].second.first.first, ans[i].second.first.second, ans[i].second.second.first, ans[i].second.second.second, ans[i].first);

	return 0;
}
