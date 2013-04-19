#include <cstdio>

long long a, b, t;
int n;

int main (){
	scanf("%d", &n);
	b = 2;
	for (int i = 2; i <= n; i++)
		t = a + b, a = b, b = t;
	printf("%I64d", b);
}

