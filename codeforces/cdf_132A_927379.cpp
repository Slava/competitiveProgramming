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

char s[5000];
int n, a[5000], last;

int rev(int x) {
	int res = 0;
	for (int i = 0; i < 8; i++) {
		res <<= 1;
		if (x & 1)
			res |= 1;
		x >>= 1;
	}
	return res;
}

int main() {
	gets(s);
	n = strlen(s);
	for (int i = 0; i < n; i++) {
		int x = s[i];
		x = rev(x);
		x = (last - x) % 256 + 256;
		x %= 256;
		last = rev(s[i]);
		printf("%d\n", x);
	}
	return 0;
}




// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Dec 3, 2011 10:38:51 PM
// contest: 132
// link: /contest/132/submission/927379
// time: 30 ms
// verdict: Accepted
// problem: 132A - Turing Tape
// ID: 927379
// downloaded by very stupid script
