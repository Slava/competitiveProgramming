#include <cstdio>
#include <cstring>
#define abs(x) (x<0?-(x):x)

char one[6000], two[6000];
int n, One[6000], Two[6000], m, k, ans;
int main() {
	scanf("%s%s", one, two);
	n = strlen(one);
	if (n != strlen(two)) {
		printf("-1");
		return 0;
	}
	for (int i = 0; i < n; i++)
		if (one[i] == '+')
			One[m++] = i;

	for (int i = 0; i < n; i++)
		if (two[i] == '+')
			Two[k++] = i;
	if (k != m) {
		printf("-1");
		return 0;
	}
	for (int i = 0; i < m; i++)
		ans += abs(One[i] - Two[i]);
	printf("%d", ans);
	return 0;
}

