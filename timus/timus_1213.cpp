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

set<string>Set;
string s;
int main() {
	cin >> s;
	Set.insert(s);
	while (cin >> s && s != "#") {
		for (int i = 0; i < s.size(); i++)
			if (s[i] == '-') {
				Set.insert(s.substr(0, i));
				Set.insert(s.substr(i + 1, s.size() - i - 1));
				break;
			}
	}
	cout << max(0, (int)Set.size() - 1);
	return 0;
}
