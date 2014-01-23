#include <cstdio>

long long ans, n;
int main (){
	scanf("%lld", &n);
	for (int i = 0; i <= n; i++)
		ans += i;
	printf("%lld", ans);
}

