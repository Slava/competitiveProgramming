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


