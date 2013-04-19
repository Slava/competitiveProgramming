#include <cstdio>
#include <algorithm>
using namespace std;

long long a[109], s;
int n, i;
int main () {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (i = 0 ; i < n; i++) {
		scanf("%I64d", &a[i]);
		s += a[i];
	}
	sort(a, a + n);
	printf("%I64d", s - a[0]);
}
