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
 
const int N = 100100;
int n, E[N];
double d[N];
vector<double> t[N], v[N];
 
double gothrough(int k, double Time, double meters) {
	if (meters < 1e-10)
		return 0;
	int l = 0, r = E[k] - 1, m;
	while (l <= r) {
		m = (l + r) / 2;
		if (t[k][m] >= Time)
			l = m + 1;
		else r = m - 1;
	}
	if(l)l--;
	double time = min(meters / v[k][l], t[k][l + 1] - t[k][l]);
	return Time + time + gothrough(k, Time + time, meters - v[k][l] * time);
}
 
double go(int k) {
	double Time = 0;
	for (int i = k; i < n; i++)
		Time = gothrough(i, Time, d[i]);
	for (int i = 0; i < k; i++)
		Time = gothrough(i, Time, d[i]);
	return Time;
}
 
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf", d + i);
		scanf("%d", E + i);
		t[i].resize(E[i]);
		v[i].resize(E[i]);
		t[i][0] = 0;
		for (int j = 1; j < E[i]; j++)
			scanf("%lf", &t[i][j]);
		t[i].push_back(1e100);
		for (int j = 0; j < E[i]; j++)
			scanf("%lf", &v[i][j]);
	}
 
	int ans = 0;
	double best = 1e100;
 
	for (int i = 0; i < n; i++) {
		double cur = go(i);
		if (cur < best) {
			best = cur;
			ans = i + 1;
		}
	}
 
	printf("%d %.10lf\n", ans, best);
 
	return 0;
}
