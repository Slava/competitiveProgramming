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

int n, ans[70000];

bool c(double A) {
	double r = sqrt(8 * A - 7);
	return (double)((int)r) == r;
}
int main() {
	scanf("%d", &n);
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		printf("%d ", c(x + 0.));
	}
	return 0;
}
