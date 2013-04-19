#include <cstdio>
#include <iostream>

using namespace std;

unsigned int n; 
int main ()
{
	freopen ("ballandbox.in", "r", stdin);
	freopen ("ballandbox.out", "w", stdout);
	cin >> n;
	n++;
	if (n%2==0)
	{
		cout << "1 / " << n / 2;
	}
	else cout << "2 / " << n;
}

