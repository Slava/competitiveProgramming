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

long long m, a, x;
int n;
int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		cin >> x; a += x;
		if (m * 3 < a) {
			cout << "Free after " << i + 1 << " times.";
			return 0;
		}
	}
	cout << "Team.GOV!";
	return 0;
}
