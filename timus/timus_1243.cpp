#include <cstdio>
#include <cstdlib>

int r;
char c;
int main() {
	while (scanf("%c", &c) == 1 && c >= '0' && c <= '9')
		r = (r * 10 + c - 48) % 7;
	printf("%d\n", r);
	return 0;
}
