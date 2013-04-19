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

int n, m, a, b;
int main() {
	scanf("%d%d%d%d", &n, &m, &a, &b);
	a--; b--;
	if (m == 1)
		printf("1\n");
	else if (a == b)
		printf("1\n");
	else if ((a % m == 0) && (b == n - 1))
		printf("1\n");
	else if ((a%m) == 0 && ((b + 1)%m) == 0)
		printf("1\n");
	else if ((a / m) == (b / m))
		printf("1\n");
	else if (b == n - 1)
		printf("2\n");
	else if ((a / m) == (b / m) - 1)
		printf("2\n");
	else if (((b + 1) % m) == 0 || (a % m) == 0)
		printf("2\n");
	else if ((a % m) == (b % m) + 1)
		printf("2\n");
	else printf("3\n");
	return 0;
}




// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Jun 30, 2011 8:41:01 PM
// contest: 93
// link: /contest/93/submission/521057
// time: 30 ms
// verdict: Accepted
// problem: 93A - Frames
// ID: 521057
// downloaded by very stupid script
