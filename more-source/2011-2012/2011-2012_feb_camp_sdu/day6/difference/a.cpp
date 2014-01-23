#include <cstdio>
#define abs(x) (x<0?-(x):x)

long long a, b;
int main() {
	scanf("%lld%lld", &a, &b);
	printf("%lld\n", abs(a-b));
	return 0;
}

