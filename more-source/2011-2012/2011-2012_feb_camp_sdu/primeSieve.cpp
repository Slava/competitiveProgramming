#include <cstdio>
#include <cstring>

const int N = 100000;
int leastPrime[N], primes[N], primesN;
int main() {
	memset(leastPrime, -1, sizeof leastPrime);
	for (int i = 2; i < N; i++) {
		if (leastPrime[i] == -1) {
			leastPrime[i] = primesN;
			primes[primesN++] = i;
		}
		for (int j = 0; j <= leastPrime[i]; j++) {
			int t = primes[j] * i;
			if (t >= N)
				break;
			leastPrime[t] = j;
		}
	}

	for (int i = 0; i < primesN; i++)
		printf("%d ", primes[i]);
	return 0;
}

