#include <cstdio>
#include <cstdlib>

bool lucky(int n) {
	while (n) {
		if (n % 10 != 4 && n % 10 != 7)
			return 0;
		n /= 10;
	}
	return 1;
}

int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		if (n % i == 0 && lucky(i)) {
			puts("YES");
			return 0;
		}
	puts("NO");
	return 0;
}




// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Oct 28, 2011 6:44:21 AM
// contest: 122
// link: /contest/122/submission/810294
// time: 30 ms
// verdict: Accepted
// problem: 122A - Lucky Division
// ID: 810294
// downloaded by very stupid script
