#include <cstdio>
#include <cstdlib>

char c; int a;
/* START */
int main (){
	while(scanf("%c", &c) == 1) {
		if (c >= '0' &&  c <= '9')
			a += c - '0';
		a %= 3;
	}
	if (a)printf("1\n%d", a);
	else printf("2");
	return 0;
}
