#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

char s[4000009];
int n, l, r, i, z[400009];

int main ()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	scanf ("%d%s", &n, s);
	for (i = 0; i < n; i++)
		s[n + i] = s[n - i - 1];
	r = -1;
	for (i = 1; i < n + n; i++)
		if (z[i - l] + i <= r)
			z[i] = z[i - l];
		else
		{
			l = i;
			if (i > r)
				 r = i;
			for (z[i] = r - i; r < n + n; ++r, ++z[i])
				if (s[r] != s[z[i]])
					break;
			r--;
		}
	for (i = 0; i < n; i++)
		printf("%d ", z[2 * n - i - 1]);
	return 0;
}

