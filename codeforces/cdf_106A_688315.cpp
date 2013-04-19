#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

string s = "6789TJQKA", a, b;
char k;

int main() {
	cin >> k;
	cin >> a >> b;
	if (a[1] == b[1]) {
		if (s.find(a[0]) > s.find(b[0]))
			cout << "YES";
		else cout << "NO";
	}
	else if (k == a[1])
		cout << "YES";
	else cout << "NO";

	return 0;
}




// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Aug 19, 2011 7:04:32 PM
// contest: 106
// link: /contest/106/submission/688315
// time: 30 ms
// verdict: Accepted
// problem: 106A - Card Game
// ID: 688315
// downloaded by very stupid script
