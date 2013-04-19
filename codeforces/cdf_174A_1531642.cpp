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
double b, a[200], sum;
int main() {
	cin >> n >> b;
	sum += b;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	for (int i = 0; i < n; i++) {
		if (a[i]*n > sum) {
			cout << "-1" << endl;
			return 0;
		}
		a[i] = sum/n-a[i];
	}

	cout.precision(7);
	for (int i = 0; i < n; i++)
		cout << fixed << a[i] << endl;
	return 0;
}




// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Apr 14, 2012 10:33:33 AM
// contest: 174
// link: /contest/174/submission/1531642
// time: 30 ms
// verdict: Accepted
// problem: 174A - Problem About Equation
// ID: 1531642
// downloaded by very stupid script
