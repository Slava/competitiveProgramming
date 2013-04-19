#include <cstdio>
#include <cstring>

int c, p = -1, n, ans;
char s[20000];
int main() {
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; i++) {
		if (p != s[i]) {
			c = 0; p = s[i];
		}
		c++;
		ans |= (c > 6);
	}
	puts(ans ? "YES" : "NO");
	return 0;
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Jul 8, 2011 10:27:45 PM
// contest: 96
// link: /contest/96/submission/537588
// time: 30 ms
// verdict: Accepted
// problem: 96A - Football
// ID: 537588
// downloaded by very stupid script
