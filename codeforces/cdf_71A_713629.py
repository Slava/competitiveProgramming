n = int(raw_input())
for i in xrange(n):
	s = raw_input()
	if len(s) > 10:
		print "%s%s%s" % (s[0], len(s) - 2, s[-1])
	else:
		print s




# lang: Python
# memory: 2800 KB
# author: imslavko
# submit_date: Sep 23, 2011 5:22:34 PM
# contest: 71
# link: /contest/71/submission/713629
# time: 60 ms
# verdict: Accepted
# problem: 71A - Way Too Long Words
# ID: 713629
# downloaded by very stupid script
