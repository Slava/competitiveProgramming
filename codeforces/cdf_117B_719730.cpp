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
#include <iomanip>
using namespace std; 

const int N = 10000010;
int a, b, mod;

int main() {
	cin >> a >> b >> mod;
	for (int i = 0; i <= min(a, mod); i++) {
		long long ost = 1000000000LL * i;
		ost %= mod;
		if ((mod - ost)%mod > b) {
			printf("1 %09d\n", i);
			return 0;
		}
	}
	cout << 2;
	return 0;
}




// lang: MS C++
// memory: 1400 KB
// author: imslavko
// submit_date: Sep 23, 2011 9:45:45 PM
// contest: 117
// link: /contest/117/submission/719730
// time: 380 ms
// verdict: Accepted
// problem: 117B - Very Interesting Game
// ID: 719730
// downloaded by very stupid script
