#include <cstdio>
#include <algorithm>

using namespace std;

int a[700], l[700], r[700], mx,
	n, ans, from[700], b[700];

bool cmp (int i, int j){
	if (l[i] == l[j])
		return r[i] < r[j];
	return l[i] < l[j];
}

int main (){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", l + i, r + i),
		a[i] = i;
	sort(a, a + n, cmp);
	b[0] = 1; from[0] = -1;
	for (int i = 1; i < n; i++){
		int mn = -1;
		for (int j = 0; j < i; j++)
			if (r[a[i]] < r[a[j]] && (mn == -1 || b[j] > b[mn]))
				mn = j;
		if (mn == -1)
			b[i] = 1, from[i] = -1;
		else b[i] = b[mn] + 1, from[i] = mn;
		if (b[i] > b[mx])
			mx = i;
	}
	printf("%d\n", b[mx]);
	for (; mx != -1; mx = from[mx])
		printf("%d ", a[mx] + 1);
	return 0;
}

