s = raw_input()
cnt = 0
for i in s:
	if i == '4' or i == '7':
		cnt += 1
lucky = cnt
while cnt:
	if cnt % 10 != 4 and cnt % 10 != 7:
		lucky = 0
	cnt /= 10
if lucky != 0:
	print "YES"
else:
	print "NO"




# lang: Python
# memory: 2800 KB
# author: imslavko
# submit_date: Sep 23, 2011 6:08:29 PM
# contest: 110
# link: /contest/110/submission/713726
# time: 80 ms
# verdict: Accepted
# problem: 110A - Nearly Lucky Number
# ID: 713726
# downloaded by very stupid script
