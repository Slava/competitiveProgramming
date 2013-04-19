#include <cstdio>
#include <cstring>

int answer, n;
int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		int divisers = 0, number = i;
		for (int j = 2; number > 1; j++)
			if (number % j == 0) {
				divisers++;
				while (number % j == 0)
					number /= j;
			}
		if (divisers == 2)
			answer++;
	}

	printf("%d\n", answer);
	return 0;
}




// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Oct 7, 2011 6:06:06 PM
// contest: 26
// link: /contest/26/submission/740787
// time: 30 ms
// verdict: Accepted
// problem: 26A - Almost Prime
// ID: 740787
// downloaded by very stupid script
