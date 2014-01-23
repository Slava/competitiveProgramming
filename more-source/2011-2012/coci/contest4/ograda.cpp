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

int n;
vector<int> slavko, mirko, a, top, hollow, order;
bool type;
// type 0,1[top,hollow] start
int main() {
	scanf("%d", &n);
	slavko.resize(n);
	mirko.resize(n);
	a.resize(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &slavko[i]);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (i && i != n-1) {
			if (slavko[i] > slavko[i-1] && slavko[i] > slavko[i+1])
				top.push_back(i);
			if (slavko[i] < slavko[i-1] && slavko[i] < slavko[i+1])
				hollow.push_back(i);
		}
	}

	order.push_back(0);
	if (slavko[0] < slavko[1]) {
		hollow.push_back(0);
		type = 0;
	}
	else {
		top.push_back(0);
		type = 1;
	}

	for (int i = 1; i < n-1; i++) {
		if (slavko[i] > slavko[i-1] && slavko[i] > slavko[i+1])
			order.push_back(i);
		if (slavko[i] < slavko[i-1] && slavko[i] < slavko[i+1])
			order.push_back(i);
	}

	if (slavko[n-1] < slavko[n-2])
		hollow.push_back(n-1);
	else top.push_back(n-1);
	order.push_back(n-1);

	sort (a.begin(), a.end());

	int beg = 0;
	for (int i = 0; i < (int)hollow.size(); i++)
		mirko[hollow[i]] = a[beg++];
	for (int i = 0; i < (int)top.size(); i++)
		mirko[top[i]] = a[--n];

	long long sum = 0;
	
	for (int i = 1; i < (int)order.size(); i++) {
		sum += abs(mirko[order[i]]-mirko[order[i-1]]);
		for (int j = order[i-1]+1; j < order[i]; j++)
			mirko[j] = (type^(i&1))?a[beg++]:a[--n];
	}

#ifdef _WIN32_
	printf("%I64d\n", sum);
#else
	printf("%Ld\n", sum);
#endif
	printf("%d", mirko[0]);
	for (int i = 1; i < (int)mirko.size(); i++)
		printf(" %d", mirko[i]);

	puts("");

	return 0;
}
