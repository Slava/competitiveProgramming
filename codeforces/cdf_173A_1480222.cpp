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
int n;
//int a, b, c, d, e, f;
string a, b;
int c[3], c2[3];

int win(char c, char C) {
	if (c == C)
		return 2;
	if (c == 'P') {
		return  (C == 'R');
	}
	if (c == 'R')
		return C == 'S';
	return C == 'P';
}

int main() {
	cin >> n;
	cin >> a >> b;
	int g = __gcd(a.size(), b.size());
	int cyc = a.size() / g * b.size();
	
	for (int i = 0; i < cyc; i++)
		c2[win(a[i%a.size()], b[i%b.size()])]++;

	int cnt = n / cyc;
	for (int i = 0; i < 3; i++)
		c[i] += c2[i] * cnt;

	n %= cyc;
	for (int i = 0; i < n; i++)
		c[win(a[i%a.size()], b[i%b.size()])]++;
	cout << c[0] << " " << c[1] << endl;

	return 0;
}




// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Apr 6, 2012 7:07:33 PM
// contest: 173
// link: /contest/173/submission/1480222
// time: 60 ms
// verdict: Accepted
// problem: 173A - Rock-Paper-Scissors
// ID: 1480222
// downloaded by very stupid script
