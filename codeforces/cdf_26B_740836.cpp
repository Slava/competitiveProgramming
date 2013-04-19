#include <cstdio>
#include <cstring>

char s[1010101];
int length, balance, answer;
int main() {
	scanf("%s", s);
	length = strlen(s);

	for (int i = 0; i < length; i++)
		if (s[i] == '(')
			balance++, answer++;
		else if (balance > 0)
			balance--, answer++;
	printf("%d\n", answer - balance);

	return 0;
}




// lang: GNU C++
// memory: 2300 KB
// author: imslavko
// submit_date: Oct 7, 2011 6:28:08 PM
// contest: 26
// link: /contest/26/submission/740836
// time: 50 ms
// verdict: Accepted
// problem: 26B - Regular Bracket Sequence
// ID: 740836
// downloaded by very stupid script
