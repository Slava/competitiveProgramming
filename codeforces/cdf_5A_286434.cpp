#include <iostream>
#include <string>

using namespace std;

int a, b;
string s;
main ()
{
	while(getline(cin, s))
		if (s[0] == '+')
			a++;
		else if (s[0] == '-')
			a--;
		else b += a * (s.size() - s.find(':') - 1);
	cout << b;
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Feb 17, 2011 8:48:13 AM
// contest: 5
// link: /contest/5/submission/286434
// time: 30 ms
// verdict: Accepted
// problem: 5A - Chat Servers Outgoing Traffic
// ID: 286434
// downloaded by very stupid script
