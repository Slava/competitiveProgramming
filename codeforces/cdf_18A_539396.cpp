#include <cstdio>

int x[3], y[3];
bool check() {
	int a = x[0] * (y[1] - y[2]) + x[1] * (y[2] - y[0]) + x[2] * (y[0] - y[1]);
	if (!a)return 0;
	for (int i = 0; i < 3; i++) {
		int x1 = x[i] - x[(i + 1) % 3],
			y1 = y[i] - y[(i + 1) % 3];
		int x2 = x[i] - x[(i + 2) % 3],
			y2 = y[i] - y[(i + 2) % 3];
		if (!(x1*x2 + y1*y2)) {
			return 1;
		}
	}
	return 0;
}

#define doit; if(check()){puts("ALMOST");return 0;}
int main() {
	for (int i = 0; i < 3; i++)
		scanf("%d%d", x + i, y + i);
	if (check()) {
		puts("RIGHT");
		return 0;
	}
	for (int i = 0; i < 3; i++) {
		x[i]++;
		doit;
		x[i] -= 2;
		doit;
		x[i]++;
		y[i]--; doit;
		y[i] += 2; doit;
		y[i]--; 
	}
	puts("NEITHER");
	return 0;
}






// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Jul 9, 2011 4:21:03 PM
// contest: 18
// link: /contest/18/submission/539396
// time: 30 ms
// verdict: Accepted
// problem: 18A - Triangle
// ID: 539396
// downloaded by very stupid script
