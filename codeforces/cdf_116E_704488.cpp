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

#define bit(x,y) ((x>>y)&1)
const int P = 1000003;

void bad() {
	puts("0");
	exit(0);
}

int main() {
	int n, m;
	cin >> n >> m;
	string s[n];
	vector< vector<int> > a(n, vector<int>(m));
	vector<int> A(n, 1), B(m, 1);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		int was = -1;
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '3' || s[i][j] == '4')
				a[i][j] |= 1;
			if (s[i][j] == '2' || s[i][j] == '3')
				a[i][j] |= 2;
			if (s[i][j] != '.') {
				if (was == -1)
					was = (j&1)^bit(a[i][j],0);
				else if (was != (j&1)^bit(a[i][j],0))
					bad();
				A[i] = B[j] = 0;
			}
		}
	}
	
	for (int j = 0; j < m; j++) {
		int was = -1;
		for (int i = 0; i < n; i++)
			if (s[i][j] != '.')
				if (was == -1)
					was = (i&1)^bit(a[i][j],1);
				else if (was != (i&1)^bit(a[i][j],1))
					bad();
	}
	
	int ans = 1;
	for (int i = 0; i < n; i++)
		ans = (ans << A[i]) % P;
	for (int j = 0; j < m; j++)
		ans = (ans << B[j]) % P;

	printf("%d\n", ans);

	return 0;
}




// lang: GNU C++
// memory: 30800 KB
// author: imslavko
// submit_date: Sep 16, 2011 2:22:25 PM
// contest: 116
// link: /contest/116/submission/704488
// time: 800 ms
// verdict: Accepted
// problem: 116E - Plumber
// ID: 704488
// downloaded by very stupid script
