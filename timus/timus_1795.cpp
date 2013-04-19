#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <deque>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std; 

typedef pair<int,int> ii;
#define f first
#define s second
map<string, int>M;
deque<ii>q;
int n, x, h[2010], m, ans;
string s, t;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> t >> s;
		M[s] = ++m;
		h[m] = x;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> t >> s;
		if (M.find(s) == M.end())
			M[s] = ++m;
		q.push_back(ii(M[s], x));
	}
	while (!q.empty()) {
		ii c = q.front(); q.pop_front();
		ans++;
		if (!h[c.f])
			continue;
		if (h[c.f] < c.s) {
			if (q.empty())
				continue;
			ii T = q.front(); q.pop_front();
			q.push_front(ii(c.f, h[c.f]));
			q.push_front(T);
		}
		else h[c.f] -= c.s;
	}
	printf("%d\n", ans);
	return 0;
}

