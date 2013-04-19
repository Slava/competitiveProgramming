#include <iostream>

using namespace std;

int a[26], n, m, p;
char c;

int main() {
	cin >> n >> m >> p;
	for (n *= m; n--; a[c - 'A']++) cin >> c;
	for (; cin >> c; a[c - 'A']--);
	for (; n < 26; n++)
		while(a[n]--)
			cout << (char)(n + 'A');
}

