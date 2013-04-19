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

set<string>Se, sE;
string s; int n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (Se.find(s) != Se.end())
			sE.insert(s);
		Se.insert(s);
	}
	for (set<string>::iterator i = sE.begin(); i != sE.end(); i++)
		cout << *i << "\n";
	return 0;
}
