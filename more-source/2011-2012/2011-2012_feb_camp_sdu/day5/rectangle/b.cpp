#include <cstdio>
#include <algorithm>
#include <set>

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
 
int n;
long long ans;
pt a[1600];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i].x, &a[i].y);

	sort(a, a+n);
	n = unique(a,a+n) - a;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) if (i != j)
			for (int k = 0; k < n; k++) if (k != i && j != k){
				pt v1 = a[j]-a[i], v2 = a[k]-a[i];
				if (v1%v2) {
					continue;
				}
				if (!binary_search(a,a+n,a[i]+v1+v2)) {
					continue;
				}
				ans = max(ans, v1*v2);
			}
	printf("%Ld\n", ans);
	return 0;
}

