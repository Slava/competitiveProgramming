#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;

int t[1000010];
char s[200]; int gx;
ll ans, k;

void inc(int i, int x = 1) {
	for (; i < 1000010; i |= i + 1)
		t[i] += x;
}

ll sum(int i) {
	ll r = 0;
	for (; i >= 0; i &= i + 1, i--)
		r += t[i];
	return r;
}

ll sum(int l, int r) {
	return sum(r) - sum(l - 1);
}

int main ()
{
	long double tt;
	while (true) {
		scanf("%s", s);
		if (s[0] == 'Q')break;
		scanf("%Lf", &tt);
		gx = (int)floorl(tt * 100. + 0.5);
		if (s[0] == 'B')
			inc(gx);
		else if (s[0] == 'D')
			inc(gx, -1);
		else {
			scanf("%I64d", &k);
			ans += min(k, sum(gx, 1000000));
		}
	}
	printf("%.2Lf\n", ans / 100.);
	return 0;
}

