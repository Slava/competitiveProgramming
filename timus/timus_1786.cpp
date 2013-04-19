#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

string a = "Sandro";
int go(string s) {
	int c = 0;
	for (int i = 0; i < 6; i++)
		if (a[i] == s[i] + 'A' - 'a' ||
			a[i] == s[i] - 'A' + 'a')
			c += 5;
		else if (a[i] == s[i])
			c += 0;
		else if ((a[i] >= 'A' && a[i] <= 'Z') == 
				(s[i] >= 'A' && s[i] <= 'Z'))
				c += 5;
		else c += 10;
	return c;
}

int main() {
	string s;
	cin >> s;
	int ans = 1 << 30;
	for (int i = 0; i + 5 < s.size(); i++) 
		ans = min(ans, go(s.substr(i, 6)));
	cout << ans;
	return 0;
}
