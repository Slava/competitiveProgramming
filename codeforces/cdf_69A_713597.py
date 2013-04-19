n = int(raw_input())
x = y = z = 0
for i in xrange(n):
	X,Y,Z = map(int, raw_input().split())
	x += X
	y += Y
	z += Z
if x == 0 and y == 0 and z == 0:
	print "YES"
else:
	print "NO"




# lang: Python
# memory: 2800 KB
# author: imslavko
# submit_date: Sep 23, 2011 5:08:21 PM
# contest: 69
# link: /contest/69/submission/713597
# time: 60 ms
# verdict: Accepted
# problem: 69A - Young Physicist
# ID: 713597
# downloaded by very stupid script
