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

map<string,int> Map;
int N, M, n[200], m[200], K;
double p[200], c[200];
char s[200];

string low(string s) {
	string t;
	for (int i = 0; i < (int)s.size(); i++)
		if (s[i] >= 'A' && s[i] <= 'Z')
			t+=s[i]-'A'+'a';
		else t+=s[i];
	return t;
}

double solve() {
	double res = 0;

	Map.clear();
	scanf("%d\n%d\n", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d\n%lf\n%lf\n", n+i, p+i, c+i);
		gets(s);
		Map[low(string(s))] = i;
	}

	for (int i = 0; i < M; i++) {
		scanf("%d\n", m+i);
		gets(s);
		string S = low(string(s));
		if (!Map.count(S))
			continue;
		int idx = Map[S],
			num = min(n[idx], m[i]);
		res += num * (p[idx]-c[idx]);
	}

	return res;
}

int main() {
#ifndef imslavko
	freopen("crisis.in", "r", stdin);
	freopen("crisis.out", "w", stdout);
#endif

	scanf("%d\n", &K);
	while(K--)
		printf("%.2lf\n", solve());

	return 0;
}
