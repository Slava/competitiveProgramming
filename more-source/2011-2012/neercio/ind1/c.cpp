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

set<pair<Int, int> >q;
map<Int, int>idx;

int n, m;
char s[1000100];
int main() {
	freopen("squirell.in", "r", stdin);
	freopen("squirell.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		int k = strlen(s) - 1;
		while (k > 0 && s[k - 1] >= '0' && s[k - 1] <= '9')
			k--;
		while (s[k] == '0')
			k++;
		int x; sscanf(s + k, "%d", &x);
		Int h = 0;
		for (int j = 0; j < k; j++) {
			h *= 27;
			h += s[j] - 'a' + 1;
		}
		x--;
		q.insert(make_pair(h, x));
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%s", s);
		Int h = 0;
		for (int j = 0; s[j]; j++) {
			h *= 27; h += s[j] - 'a' + 1;
		}
		int x = idx[h];
		while (q.find(make_pair(h, x)) != q.end())
			x++;
		x++;
		printf("%d\n", x);
		idx[h] = x;
	}

	return 0;
}
