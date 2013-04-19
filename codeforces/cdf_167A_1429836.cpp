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

double a, d;

double passed(double time, double v) {
	double need = v / a, x = 0;
	if (need < time) {
		x = need*need*a/2.;
		time -= need;
		x += time * v;
		return x;
	}
	return time*time*a/2.;
}

const int N = 100100;
int n;
double t[N], v[N] , l, r, m;
int main() {
	scanf("%d%lf%lf", &n, &a, &d);
	for (int i = 0; i < n; i++)
		scanf("%lf%lf", &t[i], &v[i]);
	double last = 0;
	for (int i = 0; i < n; i++) {
// can reach previous
		l = 0, r = 1e8+1;
		for (int iter = 0; iter < 400; iter++) {
			m = (l+r) / 2;
			if (passed(m,v[i]) >= d)
				r = m;
			else l = m;
		}

		if (r+(t[i]-(i?t[i-1]:t[i])) < last)
			r = last - (t[i]-(i?t[i-1]:t[i]));
		last = r;
		printf("%.14lf\n", last+t[i]);
	}
	return 0;
}




// lang: GNU C++
// memory: 2900 KB
// author: imslavko
// submit_date: Mar 27, 2012 8:24:45 PM
// contest: 167
// link: /contest/167/submission/1429836
// time: 1700 ms
// verdict: Accepted
// problem: 167A - Wizards and Trolleybuses
// ID: 1429836
// downloaded by very stupid script
