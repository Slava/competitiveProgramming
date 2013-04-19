// 305
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

#define i64 "%d"
typedef int ll;
const int N = 400;
int n, m;ll a[N], b[N], ans[N], used[N];
vector<int> u;
map<ll, int>mt;

bool dfs(int v)
{
	if (u[v])
		return false;
	u[v] = true;
	int too, from;
	if (a[v] > 0){
		from = -b[v] / a[v];
		too = (m - b[v]) / a[v];
	}
	else if (a[v] < 0){
		from = (m - b[v]) / a[v];
		too = -b[v] / a[v];
	}
	else from = too = 0;
	for (int i = from; i <= too; i++)
	{
		ll to = i * a[v] + b[v];
		if (i < 0 || to < 1 || to > m)continue;
		if (mt.find(to) == mt.end() || dfs(mt[to]))
		{
			mt[to] = v;
			return true;
		}
	}
	return false;
}

int main ()
{
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf (i64 i64, a + i, b + i);
	for (int i = 1; i <= n; i++)
	{
		u.assign(n + 1, 0);
		dfs(i);
	}
	
	for (map<ll,int>::iterator i = mt.begin(); i != mt.end(); ++i){
			ans[i->second] = i->first;
			if(i->first < N)
				used[i->first] = 1;
	}
	
	for (int i = 1, j = 1; i <= n; i++)
	{
		if (!ans[i]){
			for (; used[j]; j++);
			used[j] = 1;
			ans[i] = j;
		}
		printf(i64 " ", ans[i]);
	}
}

