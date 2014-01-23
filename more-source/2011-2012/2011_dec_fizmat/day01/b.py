a,b,c = map(int, raw_input().split())

def phi(n):
	res = n
	i = 2
	while i * i <= n:
		if n % i == 0:
			while n % i == 0:
				n /= i
			res -= res / i
		i = i + 1

	if n > 1:
		res -= res / n
	return res


b = (b - a + 2**32) % (2**32)



