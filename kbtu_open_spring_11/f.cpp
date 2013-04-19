#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int p, n, mx = 256;
char s[2000];
int main ()
{
	freopen ("brainfuck.in", "r", stdin);
	freopen ("brainfuck.out", "w", stdout);
	
	gets(s); n = strlen(s);
	for (int i = 0; i < n; i++)
		if (mx > (int)s[i])
			mx = (int)s[i];
	for (int i = 0; i < mx; i++)
		cout << "+";
	cout << "[";
	for (int i = 0; i < n; i++)
		cout << ">+";
	for (int i = 0; i < n; i++)
		cout << "<";
	cout << "-]";
	for (int i = 0; i < n; i++)
	{
		cout << ">";
		p = (int)s[i] - mx;
		for (;p; p--)
			cout << "+";
		cout << ".";
	}
	

	return 0;
}


