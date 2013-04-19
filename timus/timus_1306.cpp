#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>

using namespace std;

unsigned a[187505];
int n, m;
/* START */
int main (){
	scanf("%d", &n);
	for (int i = 0; i < min(n, 187505); i++) {
		scanf("%u", a + i);
	}
	sort(a, a + min(n, 187505));
	for (int i = 187505, j = 0; i < n; i++, j++) {
		scanf("%u", a + 125003 + j);
	}
	m = min(n, 187505);
	sort(a, a + m);
	if (n & 1) printf("%u.0\n", a[n / 2]);
	else printf("%.1lf\n", (a[n / 2] + a[n / 2 - 1]) / 2.);
	return 0;
}
