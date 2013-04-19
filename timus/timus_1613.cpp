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

int n, q, l, r, x;
pair<int, int> a[70100];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].first); a[i].second = i;
	}
	sort(a, a + n);
	scanf("%d", &q);
	while (q--) {
		scanf("%d%d%d", &l, &r, &x); l--; r--;
		int p = lower_bound(a, a + n, make_pair(x, l)) - a;
		if (p >= 0 && p < n && a[p].first == x && a[p].second >= l && a[p].second <= r)
			printf("1");
		else printf("0");
	}
	return 0;
}
