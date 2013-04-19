#include <cstdio>
#include <algorithm>

using namespace std;

#ifdef WIN32 
#define i64 "%I64d" 
#else 
#define i64 "%lld" 
#endif

long long l1, l2, l3, c1, c2, c3, a[10100], d[10100];
int n, i, i1, i2, i3, s, f;
int main () {
	scanf(i64 i64 i64 i64 i64 i64, &l1, &l2, &l3, &c1, &c2, &c3);
	scanf("%d%d%d", &n, &s, &f);
	if (s > f)swap(s, f);
	for (int i = 2; i <= n; i++)
		scanf(i64, d + i);
	i1 = i2 = i3 = s;
	for (int i = s + 1; i <= f; i++){
		while (d[i] - d[i1] > l1) i1++;
		while (d[i] - d[i2] > l2) i2++;
		while (d[i] - d[i3] > l3) i3++;
		if (i1 < i)a[i] = min(min(a[i1] + c1, a[i2] + c2), a[i3] + c3);
		else if (i2 < i) a[i] = min(a[i2] + c2, a[i3] + c3);
		else a[i] = a[i3] + c3;
	}
	printf(i64, a[f]);
	return 0;
}

