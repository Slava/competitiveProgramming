#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

const int N = 101010;
int n, h, t, i, k, a[N], A[N], B[N], ns, ms;
multiset<int>s;
int main ()
{
	scanf ("%d%d", &n, &k);
	for (; i < n; i++)
		scanf ("%d", a + i);
	for (t = 0; t < n; t++)
	{
		s.insert(a[t]);
		while ((*s.rbegin()) - (*s.begin())  > k)
			s.erase(s.find(a[h++])); 
		if (s.size() > ms)
			ns = 0, ms = s.size();
		if (s.size() == ms)
			A[ns] = h, B[ns++] = t;
	}

	printf("%d %d\n", ms, ns);
	for (i = 0; i < ns; i++)
		printf("%d %d\n", A[i] + 1, B[i] + 1);

	return 0;
}





// lang: GNU C++
// memory: 5700 KB
// author: imslavko
// submit_date: Feb 25, 2011 1:54:53 PM
// contest: 6
// link: /contest/6/submission/302143
// time: 130 ms
// verdict: Accepted
// problem: 6E - Exposition
// ID: 302143
// downloaded by very stupid script
