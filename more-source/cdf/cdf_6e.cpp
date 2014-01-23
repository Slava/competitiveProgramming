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

