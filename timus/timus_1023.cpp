#include <cstdio>

int n, i;
int main (){
	scanf("%d", &n);
	for (i = 3; i <= n; i++)
		if (n % i == 0)
		{
			printf("%d", i - 1);
			return 0;
		}
	puts("0");
	return 0;
}

