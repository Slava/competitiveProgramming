// closest pair
// of points on plane
// divide and conquer
// O(NlogN)
#include <cstdio>
#include <cmath>
#include <algorithm>
#define abs(x) (x<0?-(x):x)

struct Point {
	int x, y;
	Point() {}
	Point(int x, int y) : x(x), y(y) {}
	
	// default:sort by x
	bool operator < (const Point b) const {
		if (x == b.x)
			return y < b.y;
		return x < b.x;
	}
};

// distance between two points
double distance(Point a, Point b) {
	return sqrt((a.x-b.x)*1LL*(a.x-b.x)+(a.y-b.y)*1LL*(a.y-b.y));
}

// algo itself
// conquer points in range [x_l,x_r)
void conquer(int,int);
void updateAnswer(Point&,Point&);
void input();
void init();

// variables
int n;	// number of points
Point a[123456], t[123456];	// main and temp arrays
double result;

int main() {
	input();
	init();
	conquer(0,n);
	printf("%.15lf\n", result);
	return 0;
}

void updateAnswer(Point &a, Point &b) {
	double dis = distance(a,b);
	if (dis < result)
		result = dis;
}

void input() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i].x, &a[i].y);
}

void init() {
	result = 1e100;
	// sort by x
	std::stable_sort(a,a+n);
}

void conquer(int l, int r) {
	// for little ranges
	// do it manually
	if (r-l < 4) {
		for (int i = 0; i < r-l; i++)
			for (int j = l+1; j < r; j++)
				if (a[j-1].y > a[j].y)
					std::swap(a[j], a[j-1]);

		for (int i = l; i < r; i++) 
			for (int j = i+1; j < r; j++)
				updateAnswer(a[i], a[j]);
		return;
	}

	int m = (l+r)/2;	// middle
	int midx = a[m].x;	// x of mid point

	// divide
	conquer(l,m);
	conquer(m,r);
	
	// conquer
	
	// merge sort by y
	int ll = l, rr = m, j = 0;
	while (ll < m && rr < r)
		if (a[ll].y < a[rr].y)
			t[j++] = a[ll++];
		else
			t[j++] = a[rr++];

	while (ll < m)
		t[j++] = a[ll++];
	while (rr < r)
		t[j++] = a[rr++];

	for (int i = 0; i < r-l; i++)
		a[i+l] = t[i];

	// now watch all pairs of
	// points k such that
	// x_k - midx <= result
	j = 0;
	for (int k = l; k < r; k++)
		if (abs(midx-a[k].x) <= result) {
			for (int i = j-1; i >= 0 && a[k].y-t[i].y <= result; i--)
				updateAnswer(t[i],a[k]);
			t[j++] = a[k];
		}
}


