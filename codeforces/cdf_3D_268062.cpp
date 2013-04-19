#include <cstdio>
#include <queue>

using namespace std;

typedef pair<long,long> ii;
priority_queue<ii>q;
char s[100000];
long n, i, a, b, st;
long long sum;

int main ()
{
	scanf ("%s", s);
	for (; s[n]; n++);
	for (i = 0; i < n; i++)
	{
		if (s[i] == '(')
			st++;
		else if (s[i] == ')')
			st--;
		else
		{
			scanf ("%ld%ld", &a, &b);
			q.push(ii(b - a, i));
			s[i] = ')';
			sum += b;
			st--;
		}
		if (st < 0)
		{
			if (q.empty())
				break;;

			a = q.top().first;
			b = q.top().second;
			q.pop();
			s[b] = '(';
			sum -= a;
			st += 2;
		}
	}
	if (st != 0)
		{printf("-1");return 0;}
	printf("%I64d", sum);
	printf("\n%s\n", s);
	return 0;
}






// lang: GNU C++
// memory: 1900 KB
// author: imslavko
// submit_date: Jan 31, 2011 7:13:46 AM
// contest: 3
// link: /contest/3/submission/268062
// time: 50 ms
// verdict: Accepted
// problem: 3D - Least cost bracket sequence
// ID: 268062
// downloaded by very stupid script
