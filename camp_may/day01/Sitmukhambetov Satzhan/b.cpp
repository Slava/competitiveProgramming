#include <cstdio>
#include <algorithm>
using namespace std;
#define mp make_pair
#define f first
#define s second
long long ans, x, y, z, a, b, c;
pair <long long, int> d[100009];
int i, n;
int main () {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%I64d %I64d %I64d %d", &x, &y, &z, &n);
	for (i = 0;  i < n; i++) {
        scanf("%I64d %I64d %I64d", &a, &b, &c);
        d[i] = mp(a * x + b * y + c * z, i);
	}
	sort(d, d + n);
	for (i = n - 3; i < n; i++)
        printf("%d ", d[i].s + 1);
    //   ans += d[i].f;
    //printf("%I64d", ans);
}

