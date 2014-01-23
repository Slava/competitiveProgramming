#include <cstdio>
#include <cstdlib>

struct pt {
	int x, y;
}A, B;

pt a[2010];
int n, p[4020];

double best = 0;

double Area(pt C) {
	double area = (A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)) / 2.;
	if (area < 0)
		area = -area;
	if (area > best) {
		best = area;
//		printf("%d %d  %d %d  %d %d  %lf\n", A.x,A.y,B.x,B.y,C.x,C.y,area);
	}
	return area;
}

void go(int l, int r) {
	while (r - l > 2) {
		int ll = l + (r - l) / 3,
			rr = r - (r - l) / 3;
		if (Area(a[p[ll]]) > Area(a[p[rr]]))
			r = rr;
		else l = ll;
	}
	for (int i = l; i <= r; i++)
		Area(a[p[i]]);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].x, &a[i].y);
	}

	for (int i = 0; i < n; i++)
		p[i] = p[i + n] = i;

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			A = a[i]; B = a[j];
			go(i + 1, j - 1),
			go(j + 1, i + n - 1);
		}

	printf("%lf\n", best);

	return 0;
}
