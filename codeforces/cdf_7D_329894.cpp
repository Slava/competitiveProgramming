#include <cstdio>

#define min(a,b) (a<b?a:b)
const int N = 10101010;
char s[N];
int c[N], w[N], n, l, r = -1, p[N], ans;

int main ()
{
	scanf ("%s", s);
	while(s[n])n++;
	for (int i = 0; i < n; i++)
	{
		if (i <= r)
			c[i] = min(c[l + r - i], r - i) + 1;
		else c[i] = 1;
		while (i - c[i] >= 0 && i + c[i] < n && s[i - c[i]] == s[i + c[i]])
			c[i]++;
		if (i + --c[i] > r)
			r = i + c[i], l = i - c[i];
	}
	r = -1;
	for (int i = 0; i < n; i++)
	{
		if (i <= r)
			w[i] = min(w[l + r - i + 1], r - i + 1) + 1;
		else w[i] = 0;
		while (i - w[i] >= 0 && i + w[i] - 1 < n && s[i - w[i]] == s[i + w[i] - 1])
			w[i]++;
		if (i + --w[i] + 1 > r)
			l = i - w[i], r = i + w[i] - 1;
	}
	p[0] = 1;
	for (int i = 1; i < n; i++)
	{
		if (i & 1)
		{
			if (w[(i + 1) / 2] == (i + 1) / 2)
				p[i] = p[(i - 1) / 2] + 1;
		}
		else 
			if (c[(i + 1) / 2] == (i + 1) / 2)
				p[i] = p[(i - 1) / 2] + 1;
		ans += p[i];
	}
	printf("%d", ans + 1);
	return 0;
}





// lang: GNU C++
// memory: 129800 KB
// author: imslavko
// submit_date: Mar 10, 2011 6:04:29 AM
// contest: 7
// link: /contest/7/submission/329894
// time: 220 ms
// verdict: Accepted
// problem: 7D - Palindrome Degree
// ID: 329894
// downloaded by very stupid script
