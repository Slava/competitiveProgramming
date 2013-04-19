#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[] = {4,8,14,20,24,28,34,38,42,54,58,62,72,76,88,92,96}, b;
main(){
    freopen("boards.in","r",stdin);
    freopen("boards.out","w",stdout);
	scanf ("%d", &b);
	if (binary_search(a, a + 17, b))
		puts("Possible");
	else puts("Impossible");

	return 0;
}

