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


const int N = 500000;
int a[N], b[N], n;
map<int,int> M;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a+i);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", b+i);
		M[b[i]] = i;
	}

	for (int i = 0; i < n; i++) {
		a[i] = M[a[i]];
	}

	long long ans = 0;
	for (int i = 1; i < n; i++)
		if (a[i] < a[i-1]) {
			ans = n-i;
			break;
		}

	cout << ans << endl;
	

	return 0;
}




// lang: GNU C++
// memory: 11600 KB
// author: imslavko
// submit_date: May 10, 2012 8:05:01 PM
// contest: 187
// link: /contest/187/submission/1675076
// time: 440 ms
// verdict: Accepted
// problem: 187A - Permutations
// ID: 1675076
// downloaded by very stupid script
