n,x,y = map(int,raw_input().split())

l,r = 0,10**10
while l <= r:
	m = (l+r)/2
	if (m+x)*100 >= y*n:
		r = m-1
	else:
		l = m+1
	
print r+1




# lang: Python
# memory: 2800 KB
# author: imslavko
# submit_date: May 10, 2012 5:39:52 PM
# contest: 168
# link: /contest/168/submission/1672326
# time: 60 ms
# verdict: Accepted
# problem: 168A - Wizards and Demonstration
# ID: 1672326
# downloaded by very stupid script
