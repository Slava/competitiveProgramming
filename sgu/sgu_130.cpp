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
long long c[31];

int main() {
	c[0] = 1;
	for (int i = 1; i < 31; i++)
		for (int j = 0; j < i; j++)
			c[i] += c[j] * c[i-j-1];

	cin >> n;
	cout << c[n] << " " << n+1 << endl;

	return 0;
}

