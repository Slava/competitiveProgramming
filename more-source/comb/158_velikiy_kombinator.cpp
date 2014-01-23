#include <cstdio>
#include <iostream>

#define ll long long

int pr[50], prcount;
int a[51], s = 1, B = 10000;
long x[100] = {1};
bool p[201];

void C(int n, int pl)
{
	for (ll i = 2; i <= n; i++)
	{
		ll j = i;
		for (ll k = 0; j > 1 && k < prcount; k++)
			while(j%pr[k]==0)
			{
				a[k] += pl;
				j /= pr[k];
			}
	}
}

void mul(int b)
{
	int c = 0;
	for (int i = 0; i < s || c; i++)
	{
		if (i == s)
			s++;
		x[i] *= b; x[i] += c;
		c = x[i] / B;
		x[i] %= B;
	}
}

void binpow (int base, int n)
{
	for (int i = 0; i < n; i++)
		mul(base);
}
int main ()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	
	for (int i = 2; i < 201; i++)
		if (!p[i])
		{
			pr[prcount++] = i;
			for (int j = i + i; j < 201; j += i)
				p[j] = 1;
		}

	ll A, B, n;
	std::cin >> A >> n;
	A /= 5;

	C(A + n, 1);
	C(n, -1); C(A, -1);
	for (int i = 0; i < prcount; i++)
		if (a[i])
			binpow(pr[i], a[i]);
	printf("%ld", x[s-1]);
	for (int i = s - 2; i >= 0; i--)
		printf("%04ld", x[i]);
	return 0;
}

