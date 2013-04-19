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

int main() {
	int n; cin >> n;
	vector<int> v;
	for (int i = 0, x; i < n; i++) {
		cin >> x; v.push_back(x);
	}
	sort (v.begin(), v.end());
	string s;cin >> s;
	cin >> n;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		cout << v[x - 1] << endl;
	}
	return 0;
}
