#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std; 

#define int double
struct pt {
	int x, y;
};
 
inline int area (pt a, pt b, pt c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
 
inline bool intersect_1 (int a, int b, int c, int d) {
	if (a > b)  swap (a, b);
	if (c > d)  swap (c, d);
	return max(a,c) <= min(b,d);
}
 
bool intersect (pt a, pt b, pt c, pt d) {
	return intersect_1 (a.x, b.x, c.x, d.x)
		&& intersect_1 (a.y, b.y, c.y, d.y)
		&& area(a,b,c) * 1LL * area(a,b,d) <= 0
		&& area(c,d,a) * 1LL * area(c,d,b) <= 0;
}

pt a[20000], b[20000], o, oo;
int n;

int in() {
	int x; 
	cin >> x;
	return x;
}

#undef int
int main() {
	srand(1234);
	n = in();
	for (int i = 0; i < n; i++) {
		a[i].x = in(); a[i].y = in();
		b[i].x = in(); b[i].y = in();
	}
	o.x = in();
	o.y = in();

	bool border = 0;
	for (int i = 0; i < n; i++)
		if (a[i].x == b[i].x)
			border |= o.x == b[i].x && intersect_1(a[i].y,b[i].y,o.y,o.y);
		else
			border |= o.y == b[i].y && intersect_1(a[i].x,b[i].x,o.x,o.x);

	if (border)
		puts("BORDER");
	else {
		int ccc = 0;
		for (int j = 0; j < 100; j++) {
			oo.x = rand() + rand() * 1000 + rand() * 10000 + 10000000LL;
			oo.y = rand() + rand() * 1000 + rand() * 10000 + 10000000LL;
			int cc = 0;
			for (int i = 0; i < n; i++)
				cc += intersect(o,oo,a[i],b[i]);
			ccc += cc & 1;
		}
		if (ccc >= 60)
			puts("INSIDE");
		else
			puts("OUTSIDE");
		fprintf(stderr, "%d\n", ccc);
	}
	return 0;
}
