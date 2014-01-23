#include <cstdio>
#define file "a"

int a, b;
int main (){
	freopen (file ".in", "r", stdin);
	freopen ("output.txt", "w", stdout);
	
	scanf("%d%d", &a, &b);
	printf("%d", a - b);

}
