#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

bool prime[10000100];
int n;
int dp[1000][1000];
char s[20];

int go(int a, int b) {
	if (dp[a][b] != -1)
		return dp[a][b];
	if (a == 1 && b == 1)
		return dp[a][b] = 0;
	int &res = dp[a][b], x;
	s[0] = 0;
	sprintf(s, "%d%d", a, b);
	sscanf(s, "%d", &x);
	res = 0;

	if (a > 1)
		res = max(res, prime[x] + go(a-1,b));
	if (b > 1)
		res = max(res, prime[x] + go(a,b-1));
	return res;
}
 
int main() {
	memset(dp, -1, sizeof dp);
	memset(prime, 1, sizeof prime);
	prime[0] = prime[1] = 0;

	for (int i = 2; i <= 10000000; i++)
		if (prime[i]) {
			for (int j = i+i; j <= 10000000; j += i)
				prime[j] = 0;
		}

	scanf("%d", &n);
	printf("%d\n", go(n,n));

	return 0;
}

