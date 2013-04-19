#include <algorithm>
#include <cstdio>
#include <set>
#include <map>
#include <ctime>

using namespace std;

typedef pair<int,int> pii;
set<pii>s;
map<int, int>m;
const int N = 10000010;
int n, x; char cmd;
int a[N];
int main ()
{
	freopen ("C.in", "r", stdin);
	freopen ("C.out", "w", stdout);

	scanf ("%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%c %d\n", &cmd, &x);
		s.erase(pii(-m[x], x));
		if (cmd == '+')
			m[x]++;
		else
			m[x]--;
		s.insert(pii(-m[x], x));
		if (!s.size() || !s.begin()->first)
			puts("0");
		else printf("%d\n", s.begin()->second);
	}
	fprintf(stderr, "%.4lf", double(clock())/double(CLOCKS_PER_SEC));
	return 0;
}

