#include <cstdio>
#include <iostream>

#define ll long long
const int prcount = 24;
int pr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int a[24], s = 1, B = 10000;
long x[100] = {1};

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
	ll res = 1;
	ll A, B, n;
	std::cin >> n >> A >> B;
	C(A + n, 1); C(B + n, 1);
	C(n, -1); C(A, -1); C(B, -1); C(n, -1);
	for (int i = 0; i < prcount; i++)
		if (a[i])
			binpow(pr[i], a[i]);
	printf("%ld", x[s-1]);
	for (int i = s - 2; i >= 0; i--)
		printf("%04ld", x[i]);
	return 0;
}

