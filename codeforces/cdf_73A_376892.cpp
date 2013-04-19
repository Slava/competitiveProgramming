#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

long long a[3], b[3], k;
int main ()
{
	cin >> b[0] >> b[1] >> b[2] >> k;
	sort(b, b + 3);
	b[0]--, b[1]--, b[2]--;
	a[0] = min(k / 3, b[0]); k -= a[0];
	a[1] = min(k / 2, b[1]); k -= a[1];
	a[2] = min(k, b[2]);
	cout << ++a[0] * ++a[1] * ++a[2];
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Apr 10, 2011 5:32:40 PM
// contest: 73
// link: /contest/73/submission/376892
// time: 30 ms
// verdict: Accepted
// problem: 73A - The Elder Trolls IV: Oblivon
// ID: 376892
// downloaded by very stupid script
