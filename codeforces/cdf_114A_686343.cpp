#include <cstdio>
#include <cstdlib>

long long n, k;
int main() {
	scanf("%lld%lld", &n, &k);
	for (long long i = n, j = 0; i <= k; i *= n, j++)
		if (i == k) {
			printf("YES\n%lld\n", j);
			return 0;
		}
	printf("NO\n");
	return 0;
}




// lang: MS C++
// memory: 1400 KB
// author: imslavko
// submit_date: Sep 9, 2011 7:01:46 PM
// contest: 114
// link: /contest/114/submission/686343
// time: 30 ms
// verdict: Accepted
// problem: 114A - Cifera
// ID: 686343
// downloaded by very stupid script
