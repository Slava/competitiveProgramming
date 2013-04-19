#include <cstdio>
#include <cstdlib>

char s[100];
int a[10];
int main() {
	scanf("%s", s);
	for (int i = 0; s[i]; i++)
		a[s[i] - '0']++;
	if (!a[4] && !a[7])
		puts("-1");
	else if (a[7] > a[4])
		puts("7");
	else puts("4");
	return 0;
}




// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Oct 28, 2011 6:47:18 AM
// contest: 122
// link: /contest/122/submission/810311
// time: 30 ms
// verdict: Accepted
// problem: 122B - Lucky Substring
// ID: 810311
// downloaded by very stupid script
