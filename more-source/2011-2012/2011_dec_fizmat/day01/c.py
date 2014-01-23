a,b,c = map(int, raw_input().split())
af = 1
bf = 1
abf = 1
i = 1
while i <= a:
	af *= i
	i += 1

i = 1
while i <= b:
	bf *= i
	i += 1
i = 1
while i <= a-b:
	abf *= i
	i += 1
print (af / bf / abf) % c
