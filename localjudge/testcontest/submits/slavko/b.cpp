#include <cstdio>
#define file "b"

long long a, b;
int main (){
	freopen (file ".in", "r", stdin);
	freopen (file ".out", "w", stdout);
	
	scanf("%lld%lld", &a, &b);
	printf("%lld", a * b);

}
