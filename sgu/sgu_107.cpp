#include <cstdio>
#include <cstdlib>

int main() {
	int n;
	scanf("%d", &n);
	if (n < 9)
		puts("0");
	else if (n == 9)
		puts("8");
	else {
		printf("72");
		for (int i = 0; i < n-10; i++)
			printf("0");
		puts("");
	}
	return 0;
}
