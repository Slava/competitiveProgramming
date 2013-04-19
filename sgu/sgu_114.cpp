// telecasting station
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 15100;
long long forw, back, bestans, sum;
pair<long long, long long> a[N];
#define x first
#define p second
int n, ansid;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%Ld%Ld", &a[i].x, &a[i].p);
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		sum += (a[i].x-a[0].x) * a[i].p;
		if (i)
			forw += a[i].p;
	}
	back = a[0].p;
	bestans = sum;
	for (int i = 1; i < n; i++) {
		sum += (back - forw) * (a[i].x - a[i-1].x);
		back += a[i].p;
		forw -= a[i].p;
		if (sum < bestans) {
			bestans = sum;
			ansid = i;
		}
	}

	printf("%Ld.00000\n", a[ansid].x);

	return 0;
}

