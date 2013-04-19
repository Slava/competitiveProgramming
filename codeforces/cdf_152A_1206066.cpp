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
int n, m, ans, best[400];
char a[400][400];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", a[i]);
	}

	for (int j = 0; j < m; j++) {
		char bchar = 0;
		for (int i = 0; i < n; i++)
			if (bchar < a[i][j])
				bchar = a[i][j];
		for (int i = 0; i < n; i++)
			if (bchar == a[i][j])
				best[i] = 1;
	}

	for (int i = 0; i < n; i++) {
		ans+=best[i];
	}
	printf("%d\n", ans);

	return 0;
}




// lang: GNU C++
// memory: 1500 KB
// author: imslavko
// submit_date: Feb 20, 2012 7:05:29 PM
// contest: 152
// link: /contest/152/submission/1206066
// time: 30 ms
// verdict: Accepted
// problem: 152A - Marks
// ID: 1206066
// downloaded by very stupid script
