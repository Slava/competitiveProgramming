#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <map>
#include <cstring>

using namespace std;


struct bigint {
	int a[200], n;
	bigint() {
		memset(a, 0, sizeof a);
		n = 0;
	}
	void operator += (bigint b) {
		int carry = 0;
		for (int i = 0; i < 200; i++) {
			a[i] += b.a[i] + carry;
			carry = a[i] / 10;
			a[i] %= 10;
		}
	}
	void operator *= (int v) {
		int carry = 0;
		for (int i = 0; i < 200; i++) {
			a[i] = a[i] * v + carry;
			carry = a[i] / 10;
			a[i] %= 10;
		}
	}
	void out() {
		n = 200;
		while (n > 0 && !a[n - 1])
			n--;
		if (!n)
			printf("0");
		for (int i = n - 1; i >= 0; i--)
			printf("%d", a[i]);
		puts("");
	}
};

const int N = 20;
bigint A,M;
int n, m[N], a[N], x[N];
int r[N][N];
map<int,int> Phi;

int phi(int n) {
	if (Phi[n])return Phi[n];
	int res = n;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) {
			while (n % i == 0) {
				n /= i;
			}
			res -= res / n;
		}
	if (n > 1)
		res -= res / n;
	return Phi[n] = res;
}

int binpow(int a, int n, int mod) {
	long long res = 1; 
	while (n > 0) {
		if (n & 1)
			res = (res * 1LL * a) % mod;
		a = (a * 1LL * a) % mod;
		n >>= 1;
	}
	return (int)res;
}

int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

	scanf("%d", &n);
	M.a[0] = 1;
	m[0] = 1;
	int mM = 1, mA = 0;
	for (int i = 1; i <= n; i++)
		scanf("%d", m + i);

	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j)
				r[i][j] = binpow(m[i],phi(m[j])-1,m[j]);

	for (int i=1; i<=n; ++i) {
		x[i] = a[i];
		for (int j=1; j<i; ++j) {
			x[i] = r[j][i] * (x[i] - x[j]);

			x[i] = x[i] % m[i];
			if (x[i] < 0)  x[i] += m[i];
		}
	}

	for (int i = 1; i <= n; i++) {
		mA += mM * x[i];
		mM *= m[i];

		bigint MM = M; MM *= x[i];
		A += MM;
		M *= m[i];

	}

	A.out();
	
	return 0;
}
