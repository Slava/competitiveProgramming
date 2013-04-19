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

#include<climits>

using namespace std;

typedef long long Int;

Int n;
Int Min=(1LL<<60);
Int Max=-Min;;

int main() {
	cin >> n;

	for (Int i = 1; i * i <= n; i++)
		if (n % i == 0) {
			for (Int j = 1; j * j <= n / i; j++)
				if ((n/i) % j == 0) {
					Int k = n / i / j;
					Min=min(Min,-i*j*k+(i+1)*(j+2)*(k+2));
					Max=max(Max,-i*j*k+(i+1)*(j+2)*(k+2));
				}
			for (Int j = 1; j * j <= i; j++)
				if (i % j == 0) {
					Int k = i / j;
					Min=min(Min,-n/i*j*k+(n/i+1)*(j+2)*(k+2));
					Max=max(Max,-n/i*j*k+(n/i+1)*(j+2)*(k+2));
				}
			}

	cout << Min << " " << Max << endl;
	
	return 0;
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Jan 12, 2012 8:47:50 PM
// contest: 142
// link: /contest/142/submission/1038762
// time: 50 ms
// verdict: Accepted
// problem: 142A - Help Farmer
// ID: 1038762
// downloaded by very stupid script
