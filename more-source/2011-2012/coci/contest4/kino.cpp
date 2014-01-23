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
	string s;
	vector<int> a;
	int love = 0, n;
	cin >> n >> s;

	a.push_back(1);
	for (int i = 0; i < (int)s.size(); i++)
		if (s[i] == 'S')
			a.push_back(-1), a.push_back(1);
		else {
			a.push_back(-1);
			love ^= 1;
			if (!love)
				a.push_back(1);
		}


	int answer = 0;
	for (int i = 0; i < (int)a.size(); i++)
		if (a[i] == -1) {
			if (a[i-1] == 1)
				a[i-1]--;
			else if (a[i+1] == 1)
				a[i+1]--;
			else answer++;
		}

	cout << n-answer << endl;

	return 0;
}
