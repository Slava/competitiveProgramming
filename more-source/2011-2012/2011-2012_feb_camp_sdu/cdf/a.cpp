#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100100;
string s, t;
int main() {
	cin >> t >> s;
	int n = (int)s.size(), m = (int)t.size(), ans = 1<<30;
	for (int i = -max(m,n); i <= max(n,m); i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++)
			if (i+j < 0 || i+j >= m || s[j] != t[i+j])
				cnt++;
		ans = min(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}

