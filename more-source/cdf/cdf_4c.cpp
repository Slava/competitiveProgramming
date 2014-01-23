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

