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

string s;
set<string> Set;
int n, a;
int main() {
	cin >> n;
	for (int i = 0; i <= n; i++) {
		getline(cin, s);
		if (Set.find(s) != Set.end())
			a++;
		Set.insert(s);
	}
	cout << a;
	return 0;
}
