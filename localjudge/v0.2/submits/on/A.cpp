// O, velikiy System Judge!
// Posshadi menya! Plzplzplzplzplz
#include <cstdio>
#include <ctime>
#include <algorithm>

using namespace std;


long long w[30], sum, res, k, c[30], ans;
int n, m, need[30], x, p, ansm;
char s[300];
int main ()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	scanf("%d %d %lld\n", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%lld ", &w[i]);
	for (int i = 0; i < m; i++)
		scanf("%lld ", &c[i]);
	for (int i = 0; i < m; i++)
	{
		gets(s); 
		p = 0;             
		while (sscanf(s + p, "%d ", &x) == 1)
		{
			for (;s[p] >= '0' && s[p] <= '9';p++);
			for (; s[p] == ' ';p++);
			need[i] |= (1 << (x - 1));
		}
	}
	for (int x = (1 << n) - 1; x >= 0; x--)
	{
		sum = 0;
		for (int i = 0; i < n; i++)
			if (x & (1 << i))
				sum += w[i];
		if (sum > k)
			continue;
		res = 0;
		for (int i = 0; i < m; i++)
		{
			int mask = need[i] & x;
			if (mask == need[i]){
				res += c[i];
			}
		}
		if (res > ans)
		{
			ans = res;
			ansm = x;
		}
	if (double(clock()/double(CLOCKS_PER_SEC)) >= 2.9){goto out;}
	
	}
	out:
	for (int i = 0; i < n; i++)if (ansm & (1 << i))
		printf("%d ", i + 1);
	return 0;
}
// sdelay long long!

