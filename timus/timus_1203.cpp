#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 100010;
int a[N], l[N], r[N], n, R = -1, ans;

bool cmp(int i, int j){
	return r[i] < r[j];
}

int main (){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		a[i] = i;
		scanf("%d%d", l + i, r + i);
	}
	sort(a, a + n, cmp);
	for (int i = 0; i < n; i++)
		if (l[a[i]] > R){
			ans++; R = r[a[i]];
		}
	printf("%d\n", ans);
	return 0;
}

