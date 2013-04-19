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

const int N = 101010;
int n, m, s[N], f[N], t[N], a[N];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> f[i] >> t[i];
		if (s[i] == f[i]) {
			cout << t[i] << endl;
			continue;
		}
		int cyc = t[i] / (2 * m - 2);
		if (t[i] % (2 * m - 2) != 0)
			cyc++;
		cyc *= 2 * m - 2;
		if (f[i] <= s[i]) {
			int time = cyc - s[i] + 1;
			while (time - (m * 2 - 2) >= t[i])
				time -= m * 2 - 2;
			while (time < t[i])
				time += m * 2 - 2;
			a[i] = time + s[i] - f[i];
		}
		else {
			int time = cyc + s[i] - 1;
			while (time - (m * 2 -2) >= t[i])
				time -= m * 2 - 2;
			a[i] = time + f[i] - s[i];
		}
		cout << a[i] << endl;
	}
	

	return 0;
}





// lang: GNU C++
// memory: 2900 KB
// author: imslavko
// submit_date: Sep 23, 2011 7:40:31 PM
// contest: 117
// link: /contest/117/submission/714878
// time: 590 ms
// verdict: Accepted
// problem: 117A - Elevator
// ID: 714878
// downloaded by very stupid script
