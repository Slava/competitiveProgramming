#include <cstdio>

const int N = 101010;
struct mystack
{
	int a[N], n;
	mystack () {n = 0;}
	int top () {return a[n - 1];}
	void push (int x) {a[n++] = x;}
	void pop () {n--;}
}s;
int n, t, a[N], l[N], r[N], ans[N];

int main ()
{
	freopen ("RIDGE.DAT", "r", stdin);
	freopen ("RIDGE.SOL", "w", stdout);
	
	scanf ("%d %d\n", &n, &t);
	for (int i = 0; i < n; i++)
		scanf ("%d ", a + i);
	for (int i = 0; i < n; i++)
	{
		while (s.n && a[s.top()] <= a[i])
		{
			r[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	while (s.n)
	{
		r[s.top()] = n;
		s.pop();
	}
	for (int i = n - 1; i >= 0; i--)
	{
		while (s.n && a[s.top()] <= a[i])
		{
			l[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	while (s.n)
	{
		l[s.top()] = -1;
		s.pop();
	}
	for (int i = 0; i < n; i++)
		ans[i] = r[i] - l[i] - 2;
	int mx = 0, res;
	for (int i = 0; i < t && i < n; i++)
		mx += ans[i];
	res = mx;
	for (int i = t; i < n; i++)
	{
		res -= a[i - t];
		res += a[i];
		if (res > mx)
			mx = res;
	}
	printf ("%d\n", mx);
	return 0;
}

