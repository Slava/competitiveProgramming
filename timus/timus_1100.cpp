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

pair<int,int> a[150100];
int n;

bool cmp(pair<int,int> a, pair<int,int> b) {
	return a.first > b.first;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i].second, &a[i].first);
	stable_sort(a, a + n, cmp);
	for (int i = 0; i < n; i++)
		printf("%d %d\n", a[i].second, a[i].first);
	return 0;
}
