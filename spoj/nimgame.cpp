#include <cstdio>
int main (){
	int a, b, c;
	a = 2, b = 1;
	for (int i = 1; i < 16; i++){
		printf("%d\n", a);
		c = b + a;
		b = a; a = c;
	}
}
