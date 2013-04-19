#include <cstdio>
#include <cstdlib>

int m, n;
/* START */
int main (){
	scanf("%d%d", &n, &m);
	if (m > n)
		m += n, n = m - n, m -= n;
	if (m == 1)
		printf("%d", (n + 1) / 2);
	else printf("%d", (m % 3 == 0) || (n % 3 == 0) ? 2 : 1);
	return 0;
}
