#include <cstdio>
#include <algorithm>

using namespace std;

long n, v, s1, s2, ans[2000009], i, j, z;
pair<long, long>a[100009], b[100009];
#define p first
#define id second
int main ()
{
	scanf ("%ld%ld", &n, &v);
	for (i = 0; i < n; i++)
	{
		scanf ("%ld%ld", &j, &z);
		if (j&1)
			a[s1].p = z, a[s1++].id = i + 1;
		else b[s2].p = z, b[s2++].id = i + 1;
	}
	z = j = 0; 
	sort (a, a + s1); sort(b, b + s2);
	s1--, s2--;
	for (;s1 > 0 && s2 > 0; )
		if (v > 1 && b[s2].p > a[s1].p + a[s1 - 1].p)
			z += b[s2].p, ans[j++] = b[s2--].id, v -= 2;
		else 
		if (v)z += a[s1].p,  ans[j++] = a[s1--].id, v--;
		else break;
	if (!s1)
	{
		if (v&1 || a[s1].p > b[s2].p)
			v--, z += a[s1].p, ans[j++] = a[s1--].id;
		for (;v > 1 && s2 >= 0; v -= 2)
			ans[j++] = b[s2].id, z += b[s2--].p;
	}
	if (!s2)
	{
		if (v > 1 && (s1 == -1 || a[s1].p + a[s1 - 1].p < b[s2].p))
			ans[j++] = b[s2].id, z += b[s2--].p, v -= 2;
		for (; v > 0 && s1 >= 0; v--)
			ans[j++] = a[s1].id, z += a[s1--].p;
	}
	printf("%ld\n", z);
	for (i = 0; i < j; i++)
		printf("%ld ", ans[i]);

	return 0;
}





// lang: GNU C++
// memory: 10700 KB
// author: imslavko
// submit_date: Jan 27, 2011 9:31:58 AM
// contest: 3
// link: /contest/3/submission/266060
// time: 110 ms
// verdict: Accepted
// problem: 3B - Lorry
// ID: 266060
// downloaded by very stupid script
