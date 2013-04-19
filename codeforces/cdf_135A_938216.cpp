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

int n;
int a[100100];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	sort(a, a + n);
	if (a[n - 1] != 1)
		a[n - 1] = 1;
	else a[n - 1] = 2;
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}




// lang: GNU C++
// memory: 1800 KB
// author: imslavko
// submit_date: Dec 9, 2011 7:10:44 PM
// contest: 135
// link: /contest/135/submission/938216
// time: 220 ms
// verdict: Accepted
// problem: 135A - Replacement
// ID: 938216
// downloaded by very stupid script
