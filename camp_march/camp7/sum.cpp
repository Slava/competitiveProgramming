#include <cstdio>

const int N = 100100;
int t[N * 2], v[N * 2], a[N], k;
int n, i, j, cmd, l, r;

int sum (int l, int r, int i = 1, int tl = 0, int tr = n-1) {
	if (l == tl && r == tr)
		return t[i];
	int m = (tl + tr) / 2;
	if (r <= m)
		return sum (l, r, i*2, tl, m);
	if (l > m)
		return sum (l, r, i*2+1, m+1, tr);
	return sum (l, m, i*2, tl, m) + sum (m+1, r, i*2+1, m+1, tr);
}

void compit (int i = 1, int l = 0, int r = n - 1)
{
	if (l == r)
	{
		t[i] += v[i];
		t[i] -= (t[i] / k) * k;
		v[i] = 0;
	}
	else
	{
		int m = (l + r) / 2;
		v[i + i] += v[i];
		v[i + i + 1] += v[i];
		v[i] = 0;
		compit(i + i, l , m);
		compit(i + i + 1, m + 1, r);
		t[i] = t[i + i] + t[i + i + 1];
	}
}

void update (int l, int r, int i = 1, int tl = 0, int tr = n - 1)
{
	if (l == tl && r == tr)
		v[i]++;
	else
	{
		v[i + i] += v[i];
		v[i + i + 1] += v[i];
		v[i] = 0;
		int m = (tl + tr) / 2;
		if (l > m)
			update(l, r, i + i + 1, m + 1, tr);
		else if (r <= m)
			update (l, r, i + i, tl, m);
		else update(l, m, i + i, tl, m), update(m + 1, r, i + 1 + i, m + 1, tr);
	}
}

int main()
{
	freopen ("sum.in", "r", stdin);
	freopen ("sum.out", "w", stdout);
	int m;
    scanf ("%d%d%d", &n, &k, &m);
    for(i = 0; i < m; i++)
    {
        scanf ("%d%d%d", &cmd, &l, &r);
		l--, r--;
        if (cmd == 1)
		{
			update (l, r);
		}
		else 
		{
			compit();
			printf("%d\n", sum(l, r));
    	}
	}
}

