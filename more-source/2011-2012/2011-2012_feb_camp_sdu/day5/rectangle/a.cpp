#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int,int> pt;

#define x first
#define y second

pt operator + (pt a, pt b) {
	return pt(a.x+b.x, a.y+b.y);
}

pt operator - (pt a, pt b) {
	return pt(a.x-b.x, a.y-b.y);
}

long long operator * (pt a, pt b) {
	return a.x*1LL*b.y - b.x*1LL*a.y;
}

long long operator % (pt a, pt b) {
	return a.x * 1LL * b.x + a.y * 1LL * b.y;
}

long long Abs(long long x) {
	return x < 0 ? -x: x;
}

int n, k;
long long ans;
pt pts[5600];
struct rec{
	long long d;
	pt mid;
	int i, j;
	rec() {}
	rec(long long D, pt M, int I, int J) {
		d = D;
		mid = M;
		i = I;
		j = J;
	}
} a[1700500];

#define sqr(x) (x)*(x)

bool operator < (rec a, rec b) {
	return a.d == b.d ? a.mid < b.mid : a.d < b.d;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &pts[i].x, &pts[i].y);
	}
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			a[k++] = rec(sqr(pts[i].x-pts[j].x)+sqr(pts[i].y-pts[j].y), pt((pts[i].x+pts[j].x),(pts[i].y+pts[j].y)), i, j);
	sort(a, a + k);
	for (int i = 0; i < k; i++) {
		int r = i + 1;
		while (r < k && a[r].mid == a[i].mid && a[r].d == a[i].d)
			r++;
		for (int j = i; j < r; j++)
			for (int l = i; l < j; l++) {
				ans = max(ans, Abs((pts[a[j].i]-pts[a[l].i])*(pts[a[j].j]-pts[a[l].i])));
			}
		i = r-1;
	}

	printf("%Ld\n", ans);
	return 0;
}

