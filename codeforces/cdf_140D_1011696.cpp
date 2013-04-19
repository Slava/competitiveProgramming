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

int a[101], n;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	sort(a,a+n);
	int limit = 12*60 - 10, time = 0, solved = 0, passed = 10;
	for (int i = 0; i < n; i++) {
		passed += a[i];
		if (passed > 12*60)
			break;
		solved++;
		if (passed > 6*60)
			time += passed - 6*60;
	}

	printf("%d %d\n", solved, time);

	return 0;
}




// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Jan 5, 2012 7:42:26 AM
// contest: 140
// link: /contest/140/submission/1011696
// time: 30 ms
// verdict: Accepted
// problem: 140D - New Year Contest
// ID: 1011696
// downloaded by very stupid script
