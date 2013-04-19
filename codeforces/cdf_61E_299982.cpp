#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1010100;
int t[N], n;
long long ans;
void add (int x, int i)
{
	for (; i < n; i = (i + 1) | i)
		t[i] += x;
}

int sum (int i)
{
	int r = 0;
	for (; i >= 0; i = ((i + 1) & i) - 1)
		r += t[i];
	return r;
}

int sum (int l, int r)
{
	return sum(r) - sum(l - 1);
}

int main ()
{
	int b[N], a[N], gr[N], le[N];
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%d", a + i), b[i] = a[i];
	sort(b, b + n);
	for (int i = 0; i < n; i++)
		a[i] = lower_bound(b, b + n, a[i]) - b;
	for (int i = 0; i < n; i++)
	{
		gr[i] = sum(a[i], n - 1);
		le[i] = a[i] - (i - gr[i]);
		ans += (long long) (gr[i]) *(long long) le[i];
		add(1, a[i]);
	}
	printf("%I64d", ans);
	return 0;
}





// lang: GNU C++
// memory: 13200 KB
// author: imslavko
// submit_date: Feb 23, 2011 8:04:06 AM
// contest: 61
// link: /contest/61/submission/299982
// time: 1160 ms
// verdict: Accepted
// problem: 61E - Enemy is weak
// ID: 299982
// downloaded by very stupid script
