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

string p, r, s;
int main() {
	p = "0";
	r = "01";
	for (int i = 0; i < 10; i++) {
		s = r + p;
		p = r;
		r = s;
	}
	cout << s << endl;
	return 0;
}
