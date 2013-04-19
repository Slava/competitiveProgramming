#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define sc scanf
#define pr printf
#define sqr(x) ((x)*(x))
#define all(x) x.begin(),x.end()
#define eps 1e-10

struct dot {
	double x, y, z;
}p, b, T;

int n;
double vs, vp, dist, t, d[10100], best = 1e10, st, time, delta;
vector<dot>a;

bool can(double t) {
	int it = lower_bound(d, d + n, t * vs) - d;
	if (fabs(d[it] - t * vs) < eps) {
		T = a[it];
		goto calc;
	}
	st = d[it] / vs - d[it - 1] / vs;
	time = t - d[it - 1] / vs;
	delta = time / st;
	T = a[it - 1];
	T.x += (a[it].x - a[it - 1].x) * delta;
	T.y += (a[it].y - a[it - 1].y) * delta;
	T.z += (a[it].z - a[it - 1].z) * delta;
calc:
	double di = sqrt(sqr(T.x - p.x) + sqr(T.y - p.y) + sqr(T.z - p.z));
	if (di / vp <= t + eps) {
		b = T; best = t;
		return 1;
	}
	return 0;
}

int main() {
	sc("%d", &n); n++;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		sc("%lf%lf%lf", &a[i].x, &a[i].y, &a[i].z);
		if(i) {
			d[i] = sqrt(sqr(a[i].x - a[i - 1].x) +
						sqr(a[i].y - a[i - 1].y) +
						sqr(a[i].z - a[i - 1].z));
			dist += d[i];
			d[i] += d[i - 1];
		}
	}
	sc("%lf%lf", &vp, &vs);
	sc("%lf%lf%lf", &p.x, &p.y, &p.z);
	t = dist / vs;
	double l = 0, r = t, m;
	if (!can(r)) {
		puts("NO");
		return 0;
	}
	while (r - l > eps) {
		m = (l + r) / 2;
		if (can(m))
			r = m - eps;
		else l = m + eps;
	}
	printf("YES\n%.8lf\n%.8lf %.8lf %.8lf\n", best, b.x, b.y, b.z);
	return 0;
}






// lang: GNU C++
// memory: 1700 KB
// author: imslavko
// submit_date: Jul 11, 2011 3:51:13 PM
// contest: 65
// link: /contest/65/submission/541953
// time: 50 ms
// verdict: Accepted
// problem: 65C - Harry Potter and the Golden Snitch
// ID: 541953
// downloaded by very stupid script
