#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

#define f first
#define s second

int n, m, k, l, dp[110];
double di = 141.4213;
pair<int,int>a[110];
int main (){
	scanf("%d%d%d", &m, &n, &k);
	for (int i = 0; i < k; i++){
		scanf("%d%d", &a[i].s, &a[i].f);
		a[i].f--;a[i].s--;
	}
	sort(a, a + k);
	for (int i = 0; i < k; i++)
		for (int j = 0; j < i; j++)
			if (a[j].f < a[i].f && a[j].s < a[i].s)
				if (dp[j] + 1 > dp[i])
					dp[i] = dp[j] + 1;
	for (int i = 0; i < k; i++)
		l = max(l, dp[i] + 1);
	n -= l; m -= l;
	printf("%.0lf\n", (n + m) * 100 + (l * di));
	return 0;
}

