#include <vector>
#include <algorithm>

#include <stdio.h>
#include <assert.h>

using namespace std;

typedef long long Int;
const Int mod = (Int)1e9 + 7;

bool lucky(Int x) {
	if (!x) return 0;
	while (x > 0) {
		if (x % 10 != 4 && x % 10 != 7)
			return 0;
		x /= 10;
	}

	return 1;
}

Int binPowMod(Int a, Int n) {
	Int res = 1;
	while (n > 0) {
		if (n & 1LL)
			res = (res * a) % mod;
		a = (a * a) % mod;
		n >>= 1;
	}
	return res;
}

Int divMod(Int a, Int b) {
	return (binPowMod(b, mod-2) * a) % mod;
}

Int factorialStored[100010];
Int factorial(int n) {
	if (!n) return 1;
	if (factorialStored[n])
		return factorialStored[n];
	return factorialStored[n] = (factorial(n-1) * 1LL * n) % mod;
}

Int binomialCoefficient(Int n, Int k) {
	if (n < k)
		return 0;
	return divMod(factorial(n), (factorial(k) * factorial(n-k)) % mod);
}

Int dp[1024][1024];
int solve() {
	int n, k, unlucky;
	vector<int> a, luckyNumbers, count;

	assert(scanf("%d%d", &n, &k) == 2);
	unlucky = n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		assert(scanf("%d", &a[i]) == 1);
		if (lucky(a[i])) {
			luckyNumbers.push_back(a[i]);
			unlucky--;
		}
	}


	sort(luckyNumbers.begin(), luckyNumbers.end());
	luckyNumbers.resize(unique(luckyNumbers.begin(), luckyNumbers.end()) - luckyNumbers.begin());
	count.resize(luckyNumbers.size());

	for (int i = 0; i < n; i++)
		if (lucky(a[i]))
			count[lower_bound(luckyNumbers.begin(), luckyNumbers.end(), a[i]) - luckyNumbers.begin()]++;

	dp[0][0] = 1;

	for (int i = 0; i < (int)luckyNumbers.size(); i++) 
		for (int j = 0; j <= min(k,1023); j++) {
			dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % mod;
			if (j!=k)dp[i+1][j+1] = (dp[i+1][j+1] + (dp[i][j] * 1LL * count[i]) % mod) % mod;
		}

	Int res = 0;
	for (int i = 0; i <= min(k,1023); i++)
		res = (res + (binomialCoefficient(unlucky, k-i) * dp[luckyNumbers.size()][i]) % mod) % mod;

	return (int)res;
}

int main() {
	printf("%d\n", solve());
	return 0;
}





// lang: GNU C++
// memory: 13700 KB
// author: imslavko
// submit_date: Jan 23, 2012 1:52:51 PM
// contest: 145
// link: /contest/145/submission/1112198
// time: 170 ms
// verdict: Accepted
// problem: 145C - Lucky Subsequence
// ID: 1112198
// downloaded by very stupid script
