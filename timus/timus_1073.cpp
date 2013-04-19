#include <cstdio>

int a[60100], n;
int main (){
	scanf("%d", &n);
	a[1] = 1;
	for (int i = 2; i <= n; i++){
		a[i] = (1 << 30);
		for (int j = 1; j * j <= i; j++)
			if (a[i] > a[i - j * j] + 1)
				a[i] = a[i - j * j] + 1;
	}
	printf("%d\n", a[n]);
	return 0;
}

