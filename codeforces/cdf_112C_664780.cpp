#include <iostream>

using namespace std;

long long n, x, y, i = 1;

int main() {
	cin >> n >> x >> y;
	if (y < n || (y - n + 1) * (y - n + 1) + n - 1 < x)
		cout << -1;
	else
		for (cout << y - n + 1; i < n; i++)
			cout << endl << 1;
	return 0;
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Sep 3, 2011 6:44:03 PM
// contest: 112
// link: /contest/112/submission/664780
// time: 110 ms
// verdict: Accepted
// problem: 112C - Petya and Inequiations
// ID: 664780
// downloaded by very stupid script
