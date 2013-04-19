#include <cstdio>
#include <cstdlib>
#include <cassert>

void NO() {
	puts("-1");
	exit(0);
}

int main() {
	int a4, a7, a47, a74;
	assert(scanf("%d%d%d%d", &a4, &a7, &a47, &a74) == 4);

	if (abs(a47-a74) > 1)
		NO();
	if (a47 > a74) {
		a4 -= a47; a7 -= a47;
		if (a4 < 0 || a7 < 0)
			NO();
		for (int i = 0; i <= a4; i++)
			printf("4");
		for (int i = 0; i < a74; i++)
			printf("74");
		for (int i = 0; i <= a7; i++)
			printf("7");
	}
	else if (a47 == a74) {
		a4 -= a47; a7 -= a47;
		if (a4 < 0 || a7 < 0)
			NO();
		if (a4 > 0) {
			a4--;
			for (int i = 0; i <= a4; i++)
				printf("4");
			for (int i = 1; i < a74; i++)
				printf("74");
			for (int i = 0; i <= a7; i++)
				printf("7");
			printf("4");
		} else if (a7 > 0) {
			a7--;
			printf("7");
			for (int i = 0; i <= a4; i++)
				printf("4");
			for (int i = 1; i < a74; i++)
				printf("74");
			for (int i = 0; i <= a7; i++)
				printf("7");
		} else NO();
	}
	else {
		a4 -= a74; a7 -= a74;
		if (a4 < 0 || a7 < 0)
			NO();
		printf("7");
		for (int i = 0; i <= a4; i++)
			printf("4");
		for (int i = 2; i < a74; i++)
			printf("74");
		for (int i = 0; i <= a7; i++)
			printf("7");
		printf("4");
	}

	return 0;
}

// 4747
// 474
// 7474




// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Jan 23, 2012 2:39:00 PM
// contest: 145
// link: /contest/145/submission/1112256
// time: 170 ms
// verdict: Accepted
// problem: 145B - Lucky Number 2
// ID: 1112256
// downloaded by very stupid script
