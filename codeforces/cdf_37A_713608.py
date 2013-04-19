n = int(raw_input())
a = [0] * 1001
b = map(int, raw_input().split())
for i in xrange(n):
	a[b[i]] += 1
mx = cnt = 0
for i in xrange(1001):
	mx = max(mx, a[i])
	if a[i] != 0:
		cnt += 1
print mx, cnt




# lang: Python
# memory: 2800 KB
# author: imslavko
# submit_date: Sep 23, 2011 5:14:49 PM
# contest: 37
# link: /contest/37/submission/713608
# time: 60 ms
# verdict: Accepted
# problem: 37A - Towers
# ID: 713608
# downloaded by very stupid script
