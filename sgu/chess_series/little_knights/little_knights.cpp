#include <cstdio>
#include <utility>
#include <vector>
#define bit(x,y) (((x)>>(y))&1)

using namespace std;

const int N = 28562;
int n, k, ln, num[1 << 10];
long long a[11][N][110];
pair<int,int> good[N];
long long ans;

int no[500000], he[N], ne[500000];
int nn = 1;

void add (int p, int x)
{
	no[nn] = x;
	ne[nn] = he[p];
	he[p] = nn++;
}

void check (int m1, int m2)
{
	for (int i = 0; i < n; i++)
		if (bit(m1,i))
		{
			if (i - 2 >= 0 && bit(m2, i - 2))
				return;
			if (i + 2 < n && bit(m2, i + 2))
				return;
		}
	good[ln++] = make_pair(m1, m2);
	if (!m1 && num[m2] <= k)
		a[0][ln - 1][num[m2]] = 1;
}

void check2(int x, int y)
{
	if (good[x].second != good[y].first)
		return;
	int m1 = good[x].first, m2 = good[y].second;
	for (int i = 0; i < n; i++)
		if (bit(m1, i))
			if ((i && bit(m2,i - 1)) || (i + 1 < n && bit(m2, i + 1)))
				return;
	add(x, y);
//	show(good[x].first);show(good[x].second);show(good[y].second);printf("\n");
}

int count (int x)
{
	int s = 0;
	for (int i = 0; i < n; i++)
		s += bit(x, i);
	return s;
}

int main ()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < (1 << n); i++)
		num[i] = count(i);
	for (int i = 0; i < (1 << n); i++)
		for (int j = 0; j < (1 << n); j++)
			check(i, j);
	for (int i = 0; i < ln; i++)
		for (int j = 0; j < ln; j++)
			check2(i, j);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < ln; j++){
			for (int m = 0; m <= k; m++)if (a[i][j][m])
				for (int l = he[j]; l; l = ne[l])
				{
					int to = no[l], 
					newk = m + num[good[to].second];
					if (newk <= k)
						a[i + 1][to][newk] += a[i][j][m];
				}
			}
		}
for (int j = 0; j <= k; j++){
		ans = 0;
	for (int i = 0; i < ln; i++)
		ans += a[n - 1][i][j];
	printf("%lldLL, ", ans);
	}
	return 0;
}

