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

#b = b % phi(c)
res = 1


while b > 0:
	if b % 2 == 1:
		res = res * a
		res %= c
	a = a * a
	a %= c
	b /= 2

print res

