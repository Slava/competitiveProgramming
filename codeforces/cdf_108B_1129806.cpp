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

vector<int> a;
int n;
int main() {
	scanf("%d", &n);
	a.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	sort (a.begin(), a.end());
	a.resize(unique (a.begin(), a.end()) - a.begin());

	for (int i = 1; i < (int)a.size(); i++)
		if (a[i-1]*2>a[i]) {
			puts("YES");
			return 0;
		}
	puts("NO");
	return 0;
}




// lang: GNU C++
// memory: 1800 KB
// author: imslavko
// submit_date: Feb 1, 2012 10:24:58 AM
// contest: 108
// link: /contest/108/submission/1129806
// time: 80 ms
// verdict: Accepted
// problem: 108B - Datatypes
// ID: 1129806
// downloaded by very stupid script
