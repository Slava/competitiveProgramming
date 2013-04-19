#include <cstdio>

int a[60] = {0, 1, 1}, n;
int main (){
	scanf("%d", &n);
	for (int i = 3; i <= n; i++)
		a[i] = a[i - 1] + a[i - 3] + 1;
	printf("%d\n", a[n]);
	return 0;
}
