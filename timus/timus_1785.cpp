#include <cstdio>
#include <cstdlib>

int main() {
	int n;
	scanf("%d", &n);
	if (n >= 1000)
		printf("legion");
	else if (n >= 500)
		printf("zounds");
	else if (n >= 250)
		printf("swarm");
	else if (n >= 100)
		printf("throng");
	else if (n >= 50)
		printf("horde");
	else if (n >= 20)
		printf("lots");
	else if (n >= 10)
		printf("pack");
	else if (n >= 5)
		printf("several");
	else printf("few");
	return 0;
}
