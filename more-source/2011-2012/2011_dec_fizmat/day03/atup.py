mod = 1000000007

def binpow(n,k):
	res = 1
	while k > 0:
		if k % 2 == 1:
			res = (res * n) % mod
		n = (n * n) % mod
		k /= 2
	return res


n,k = map(int,raw_input().split())
sum = 0
for i in xrange(n):
	sum = (sum + binpow(i + 1, k)) % mod

print sum
