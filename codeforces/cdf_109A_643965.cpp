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

int n;
int a[1000100];
int main() {
	cin >> n;
	for (int i = 1; i < 1000100; i++)
		a[i] = (1 << 30);
	for (int i = 0; i <= n; i++) {
		a[i + 4] = min(a[i + 4], a[i] + 1);
		a[i + 7] = min(a[i + 7], a[i] + 1);
	}
	if (a[n] == (1 << 30))
		printf("-1\n");
	else {
		for (int sev = 0; sev <= n; sev++) {
			int left = n - sev * 7;
			if (left % 4 == 0 && (left / 4 + sev) == a[n]) {
				cout << string(left / 4, '4') << string(sev, '7');
				return 0;
			}
		}
	}
	return 0;
}




// lang: GNU C++
// memory: 5400 KB
// author: imslavko
// submit_date: Aug 29, 2011 8:16:00 PM
// contest: 109
// link: /contest/109/submission/643965
// time: 30 ms
// verdict: Accepted
// problem: 109A - Lucky Sum of Digits
// ID: 643965
// downloaded by very stupid script
