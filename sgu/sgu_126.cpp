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

long long a, b, c;
int main() {
	cin >> a >> b;
	c = a + b;

	int moves = 0;
	while (a && b) {
		if (a < b) {
			b -= a;
			a <<= 1;
		} else {
			a -= b;
			b <<= 1;
		}
		moves++;
		if (moves > 31) {
			puts("-1");
			return 0;
		}
	}

	printf("%d\n", moves);
	
	return 0;
}

