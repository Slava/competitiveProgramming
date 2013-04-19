#include <cstdio>
#define abs(x) (x<0?-(x):x)

int n, sum, a[30], ans = (1 << 30);
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i); sum += a[i];
	}
	for (int m = 0; m < (1 << n); m++) {
		int s = 0;
		for (int i = 0; i < n; i++) 
			s += ((m >> i) & 1) * a[i];
		if (abs(sum - s - s) < ans)
			ans = abs(sum - s - s);
	}
	printf("%d\n", ans);
	return 0;
}
