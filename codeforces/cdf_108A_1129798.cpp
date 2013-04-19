#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

int h, m;
char s[2000], t[200];

void plusplus() {
	m++;
	if (m == 60) {
		m = 0;
		h++;
		if (h == 24)
			h = 0;
	}
}

bool pal() {
	sprintf(s, "%02d:%02d", h, m);
	strcpy(t, s);
	reverse(s,s+5);
	return !strcmp(s,t);
}

int main() {
	scanf("%d:%d", &h, &m);
	plusplus();
	while (!pal()) {
		plusplus();
	}

	printf("%02d:%02d\n", h, m);
	return 0;
}




// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Feb 1, 2012 10:19:35 AM
// contest: 108
// link: /contest/108/submission/1129798
// time: 30 ms
// verdict: Accepted
// problem: 108A - Palindromic Times
// ID: 1129798
// downloaded by very stupid script
