#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

string s;
struct big
{
	int a[40], n;
	big ()	{	n = 0;	}
	bool operator < (big &b)
	{
		if (n < b.n)
			return 1;
		if (n > b.n)
			return 0;
		for (int i = n - 1; i >= 0; i--)
			if (a[i] < b.a[i])
				return 1;
			else if (a[i] > b.a[i])
				return 0;
		return 0;
	}
	bool operator == (big &b)
	{
		if (n != b.n)
			return 0;
		for (int i = 0; i < n; i++)
			if (a[i] != b.a[i])
				return 0;
		return 1;
	}
	void div2 ()
	{
		int c = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			a[i] += c * 10;
			c = a[i] %2;
			a[i] /= 2;
			if (i == n - 1 && !a[i])n--;
		}
	}
	void scan ()
	{
		cin >> s; n = s.size();
		for (int i = 0; i < n; i++)
			a[i] = s[n - i - 1] - '0';
	}
	void print ()
	{
		for (int i = n - 1; i >= 0; i--)
			printf("%d", a[i]);
	}
}a, b;

int main ()
{
	int n;
	scanf ("%d\n", &n);
	a.scan(); b.scan();
	while (!(a == b))
		if (a < b)
			b.div2();
		else a.div2();
	a.print();
	return 0;
}

