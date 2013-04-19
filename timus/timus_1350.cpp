#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <set>

using namespace std;

set<string> Set;
string s;
int n, m, k, dan[110];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		Set.insert(s);
	}

	cin >> k >> m;
	for (int i = 0; i < m; i++) {
		cin >> s;
		Set.erase(s);
	}

	n = Set.size();
	for (int i = 0; i < k; i++) {
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> s;
			dan[i] += Set.count(s);
		}
	}

	cin >> m;
	for (int i = 0; i < k; i++) {
		if (dan[i] == 0)
			puts("YES");
		else if (dan[i] > n - m)
			puts("NO");
		else puts("MAYBE");
	}

	return 0;
}

