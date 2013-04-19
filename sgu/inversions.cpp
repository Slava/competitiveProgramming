// 180
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 70000;
long long a[N], t[N], b[N], ans;
int n;

void inc (int i, int x)
{
	for (; i < n; i |= (i + 1))
		t[i] += x;
}

long long sum (int i)
{
	long long r = 0;
	for (; i >= 0; i &= (i + 1), i--)
		r += t[i];
	return r;
}

long long sum (int l, int r)
{
	return sum(r) - sum(l - 1);
}

int main ()
{
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%I64d", a + i), b[i] = a[i];
	sort (b, b + n);
	for (int i = 0; i < n; i++)
	{
		int p = lower_bound(b, b + n, a[i]) - b;
		ans += sum(p + 1, n - 1);
		inc(p, 1);
	}
	printf("%I64d\n", ans);
	return 0;
}

