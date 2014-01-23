#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1000100;
int n, a[N], l[N], r[N], c[N];
long long ans;
int main ()
{
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%d", a + i);
	rotate (a, max_element(a, a + n), a + n);
	a[n] = a[0];
	for (int i = n - 1; i >= 0; i--)
	{
		r[i] = i + 1;
		while (r[i] < n && a[r[i]] < a[i])
			r[i] = r[r[i]];
		if (r[i] < n && a[r[i]] == a[i])
			c[i] = c[r[i]] + 1,
			r[i] = r[r[i]];
	}
	for (int i = 0; i < n; i++)
	{
		ans += c[i];
		if (a[i] == a[0])
			continue;
		l[i] = i - 1;
		while (l[i] > 0 && a[l[i]] <= a[i])
			l[i] = l[l[i]];
		ans++;ans++;
		if (l[i] == 0 && r[i] == n)
			ans--;
	}
	printf("%I64d", ans);

	return 0;
}

