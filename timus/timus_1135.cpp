#include <cstdio>
#include <cstdlib>
#include <set>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std; 

char c; int n, l, r;
int main() {
	cin >> n;
	while (cin >> c) {
		if (c == '<')
			l += r;
		if (c == '>')
			r++;
	}
	cout << l;
	return 0;
}
