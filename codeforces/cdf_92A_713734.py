n, m = map(int, raw_input().split())
cur = 1
while m > 0:
	if m < cur:
		break
	m -= cur
	cur += 1
	if cur == n + 1:
		cur = 1
print m




# lang: Python
# memory: 2800 KB
# author: imslavko
# submit_date: Sep 23, 2011 6:13:56 PM
# contest: 92
# link: /contest/92/submission/713734
# time: 50 ms
# verdict: Accepted
# problem: 92A - Chips
# ID: 713734
# downloaded by very stupid script
