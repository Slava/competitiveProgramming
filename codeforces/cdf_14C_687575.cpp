#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>

using namespace std;

#define x1 first.first
#define x2 second.first
#define y1 first.second
#define y2 second.second
typedef pair<pair<int,int>,pair<int,int> > line;
line a[4];

/*
   1
--------------
|            |
| 3          | 4
|            |
--------------
	2
 */

void dotry() {
	if (a[0].y1 != a[0].y2 ||
		a[1].y1 != a[1].y2 ||
		a[2].x1 != a[2].x2 ||
		a[3].x1 != a[3].x2 ||
	   	a[0].y1 >= a[1].y1 ||
		a[2].x1 >= a[3].x1 ||
		a[0].x1 != a[2].x1 ||
		a[0].y1 != a[2].y1 ||
		a[3].x1 != a[0].x2 ||
		a[0].y1 != a[3].y1 ||
		a[1].x1 != a[2].x1 ||
		a[1].y1 != a[2].y2 ||
		a[1].x2 != a[3].x1 ||
		a[1].y1 != a[3].y2
		)
		return;
	puts("YES");
	exit(0);
}

int main() {
	for (int i = 0; i < 4; i++) {
		scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
		if (a[i].x1 > a[i].x2)
			swap(a[i].x1, a[i].x2);
		if (a[i].y1 > a[i].y2)
			swap(a[i].y1, a[i].y2);
		if (a[i].x1 != a[i].x2 && a[i].y1 != a[i].y2) {
			puts("NO");
			return 0;
		}
	}
	sort(a, a + 4);
	do dotry();
   	while(next_permutation(a, a + 4));
	puts("NO");
	return 0;
}




// lang: MS C++
// memory: 1400 KB
// author: imslavko
// submit_date: May 19, 2010 8:01:18 PM
// contest: 14
// link: /contest/14/submission/687575
// time: 30 ms
// verdict: Accepted
// problem: 14C - Four Segments
// ID: 687575
// downloaded by very stupid script
