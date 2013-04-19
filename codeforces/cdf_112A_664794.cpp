#include <iostream>
#include <string>

using namespace std;

string a, b;
int main() {
	cin >> a >> b;
	for (int i = 0; i < (int)a.size(); i++)
		if (a[i] >= 'A' && a[i] <= 'Z')
			a[i] = a[i] - 'A' + 'a';
	for (int i = 0; i < (int)b.size(); i++)
		if (b[i] >= 'A' && b[i] <= 'Z')
			b[i] = b[i] - 'A' + 'a';
	if (a < b)
		cout << -1;
	else if (a > b)
		cout << 1;
	else cout << 0;
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Sep 3, 2011 6:44:25 PM
// contest: 112
// link: /contest/112/submission/664794
// time: 30 ms
// verdict: Accepted
// problem: 112A - Petya and Strings
// ID: 664794
// downloaded by very stupid script
