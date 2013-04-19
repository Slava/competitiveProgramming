#include <cstdio>
#include <cstring>

char s[210];
struct big
{
	int a[210], sz;
	big ()
	{
		sz = 1;
		for (int i = 0; i < 210; i++)
			a[i] = 0;
	}
	void scan ()
	{
		scanf ("%s", s);
		sz = strlen(s);
		for (int i = 0; i < sz; i++)
			a[i] = s[sz - i - 1] - '0';
	}
	void print ()
	{
		for (int i = sz - 1; i >= 0; i--)
			printf("%d", a[i]);
	}
	void operator = (int b)
	{
		sz = 1;
		a[0] = b;
	}
	void operator = (big b)
	{
		for (int i = 0; i < 210; i++)
			a[i] = b.a[i];
		sz = b.sz;
	}
	void div (int w)
	{
		int carry = 0;
		for (int i = sz - 1; i >= 0; i--)
		{
			a[i] += carry * 10;
			carry = a[i] % w;
			a[i] /= w;
			if (!a[i] && i && i == sz - 1)
				sz--;
		}
	}
};

big operator + (big a, big b)
{
	big c = a;
	int carry = 0;
	for (int i = 0; i < c.sz || i < b.sz || carry; i++)
	{
		if (i == c.sz)
			c.sz++;
		c.a[i] += b.a[i] + carry;
		carry = c.a[i] / 10;
		c.a[i] %= 10;
	}
	return c;
}

big operator - (big a, big b)
{
	big c = a;
	int carry = 0;
	for (int i = 0; i < c.sz || carry; i++)
	{
		c.a[i] -= carry + b.a[i];
		if (c.a[i] < 0)
		{
			c.a[i] += 10;
			carry = 1;
		}
		else carry = 0;
	}
	while (c.sz > 1 && !c.a[c.sz - 1])
		c.sz--;
	return c;
}

big operator * (big a, big b)
{
	big c; c.sz = a.sz + b.sz;
	int carry = 0, i, j, t;
	for (i = 0; i < a.sz; i++)
	{
		for (j = 0; j < b.sz || carry; j++)
		{
			t = a.a[i] * b.a[j] + carry;
			c.a[i + j] += t;
			carry = c.a[i + j] / 10;
			c.a[i + j] %= 10;
		}
	}
	for (c.sz = 210; c.sz > 1 && !c.a[c.sz - 1];)c.sz--;
	return c;
}

big n, x, y, two, one, ans;

int main()
{
	one = 1;
	two = 2;
	freopen("room.in", "r", stdin);
	freopen("room.out", "w", stdout);
	n.scan();
//n.print();puts(" it was n");

	y = (n + two); y.div(3);
//y.print(); puts(" it was y");
	x = n - y;
	x = x * (x + one); x.div(2);
//x.print(); puts(" it was x");
	ans = y * y;
//ans.print(); puts(" ans = y * y");
	ans = ans + x;
//ans.print(); puts(" + x");
	ans.print();
	return 0;
}

