#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, a[500100], A, B;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	sort(a, a + n);
	for (int i = 0; i < n; ) {
		int p = upper_bound(a, a + n, a[i]) - lower_bound(a, a + n, a[i]);
		if (p > A) {
			A = p; B = a[i];
		}
		i = upper_bound(a, a + n, a[i]) - a;
	}
	printf("%d\n", B);
	return 0;
}
