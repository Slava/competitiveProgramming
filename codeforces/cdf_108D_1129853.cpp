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

int n, m, h, sum;
int a[1005];

double cnk(int n, int k) {
	double res = 1;
	for (int i = 1; i <= k; i++)
		res = res * (n-k+i+0.) / (i*1.);
	return res;
}

int main() {
	scanf("%d%d%d", &m, &n, &h);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	a[h]--; m--;

	for (int i = 1; i <= n; i++)
		sum += a[i];

	if (sum < m) {
		puts("-1");
		return 0;
	}
	
	if (!m) {
		puts("0");
		return 0;
	}

	if (m > sum-a[h]) {
		puts("1");
		return 0;
	}

	printf("%.15lf\n", 1.-cnk(sum-a[h],m)/cnk(sum,m));
	return 0;
}




// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Feb 1, 2012 11:07:49 AM
// contest: 108
// link: /contest/108/submission/1129853
// time: 30 ms
// verdict: Accepted
// problem: 108D - Basketball Team
// ID: 1129853
// downloaded by very stupid script
