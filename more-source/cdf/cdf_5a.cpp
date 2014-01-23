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

