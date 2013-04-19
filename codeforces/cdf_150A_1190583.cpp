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

long long q, a, b;
int main() {
	cin >> q;
	int cnt = 0;
	for (long long i = 2; i * i <= q; i++)
		while (q % i == 0) {
			cnt++;
			if (cnt == 1) a = i;
			else if (cnt == 2)b = i;
			q /= i;
			if (cnt == 2 && q != 1) {
				cout << 1 << endl;
				cout << a * b << endl;
				return 0;
			}
		}


	if (!cnt)
		cout << 1 << endl << 0 << endl;
	else cout <<  2 << endl;
	return 0;
}




// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Feb 17, 2012 7:39:36 PM
// contest: 150
// link: /contest/150/submission/1190583
// time: 60 ms
// verdict: Accepted
// problem: 150A - Win or Freeze
// ID: 1190583
// downloaded by very stupid script
