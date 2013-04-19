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

#define abs(x) (x<0?-(x):x)

const int N = 100100;
int n;
pair<int,int> a[N];

int f(int x) {
	int res = 1;
	if (!x) return 0;
	for (; x; x /= 10)
		res *= (x%10);
	return res;
}

int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a[i] = make_pair(f(x), x);
	}
	
	sort(a,a+n);
	pair<int,pair<int,int> > ans = make_pair(1<<30, make_pair(0,0));

	for (int i = 1; i < n; i++)
		ans = min(ans, make_pair(abs(a[i].first-a[i-1].first),make_pair(a[i-1].second,a[i].second)));
	
	printf("%d %d\n", ans.second.first, ans.second.second);

	return 0;
}

