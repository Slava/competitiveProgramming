// 276
#include <cstdio>

int a, b, c, ans;
int main ()
{
	scanf ("%d%d", &a, &b);
	b -= a;
	if (b > 0)
	{
		c = b / 60;
		ans = 1;
		if (c >= 5)
			ans++;
		if (c >= 15)
			ans++;
		if (c >= 30)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}

