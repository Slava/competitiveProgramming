s1 = raw_input()
s2 = raw_input()

f,s = [0,0]
for a,b in zip(s1,s2):
	if a != b:
		if a == '4':
			f += 1
		else:
			s += 1

print f+s-min(f,s)




# lang: Python
# memory: 7600 KB
# author: imslavko
# submit_date: Feb 7, 2012 6:27:08 PM
# contest: 145
# link: /contest/145/submission/1155934
# time: 110 ms
# verdict: Accepted
# problem: 145A - Lucky Conversion
# ID: 1155934
# downloaded by very stupid script
