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

int main() {
	int a, b, n, ans = 0, c = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		c += b - a;
		ans = max(ans, c);
	}
	printf("%d\n", ans);
	return 0;
}




// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Sep 15, 2011 7:02:58 PM
// contest: 116
// link: /contest/116/submission/695792
// time: 30 ms
// verdict: Accepted
// problem: 116A - Tram
// ID: 695792
// downloaded by very stupid script
