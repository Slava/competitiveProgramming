#include <cstdio>
#include <cstdlib>

typedef long long Int;

Int x, y;
Int gcd(Int a, Int b) {
	Int x1 = 1, y1 = 0, x2 = 0, y2 = 1;
	while (a > 0 && b > 0) {
		if (a > b) {
			Int t = a / b;
			a -= t * b;
			x1 -= t * x2;
			y1 -= t * y1;
		} else {
			Int t = b / a;
			b -= t * a;
			x2 -= t * x1;
			y2 -= t * y1;
		}
	}
	x = x1 + x2;
	y = y1 + y2;
	return a + b;
}

#ifdef WIN32
#define lld "%I64d"
#else
#define lld "%lld"
#endif

typedef long long ll;

int main() {
	Int a, b, c, m = 1LL << 32;
	Int A, B;
	scanf(lld lld lld, &a, &b, &c);
	
	A = c; B = m;

	if (!c) {
		if (a != b)
			puts("-1");
		else printf("0\n");
		return 0;
	}

	b = (b - a + m) % m;
	Int d = gcd(c, m);

//	printf("%lld * x - m * y == %lld\n", c,b);

	if (b % d != 0) {
		puts("-1");
		return 0;
	}
	
	x *= b;
	x /= d;

	y *= b;
	y /= d;

	A /= d;
	B /= d;

	Int cnt = -x / B;
	while (x + cnt * B < 0)
		cnt++;
	Int mx = x + cnt * B, my = y - cnt * A;

	printf(lld "\n", mx);
//	fprintf(stderr, "\nans = " lld "\n", ((x*c-m*y)%m+m)%m);
//	fprintf(stderr, "\nans = " lld "\n", ((mx*c-m*my)%m+m)%m);

	return 0;
}
