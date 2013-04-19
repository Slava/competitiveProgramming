#include <cstdio>
#include <string>
#include <iostream>
#include <map>

using namespace std;

map<string, int>m;
int main ()
{
	int n, i, a;string s;
	scanf ("%d", &n);
	for (i = 0; i < n; i++)
	{
		cin >> s;
		a = m[s];
		if (a)
			cout << s << a << "\n";
		else puts("OK");
		m[s]++;
	}
	return 0;
}





// lang: GNU C++
// memory: 2100 KB
// author: imslavko
// submit_date: Feb 13, 2011 1:30:07 PM
// contest: 4
// link: /contest/4/submission/283946
// time: 830 ms
// verdict: Accepted
// problem: 4C - Registration System
// ID: 283946
// downloaded by very stupid script
