#include <cstdio>
#include <cstdlib>

int n, m, ok = 1, a[200], sum;
/* START */
int main (){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		if(a[i] > m)ok = 0;
	}
	for (int i = 0; i < n; i++) {
		sum += a[i] - 1;
	}sum++;
	if(sum >= m && ok)puts("yes");
	else puts("no");
	return 0;
}
