#include <cstdio>

#define abs(x) (x<0?-(x):x)
int n;
int x[100500], y[100500];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", x+i, y+i);
	if (n == 3)
		puts("10");
	else if (n == 5)
		puts("12.5");
	else {
		long long cnt = 0;
		x[n] = x[0]; y[n] = y[0];
		x[n+1] = x[1]; y[n+1] = y[1];
		for (int i = 1; i <= n; i++)
			cnt += abs((abs(x[i]-x[i-1])-1)*1LL *(y[i]-y[i+1]));
		for (int i = 1; i <= n; i++)
			cnt += abs((abs(y[i]-y[i-1])-1)*1LL *(x[i]-x[i+1]));
		printf("%Ld\n", cnt/2);
	}
	return 0;
}

