#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int LEN = 250010 * 2;
//typedef unsigned long long ull;
typedef unsigned int ull;
ull pr[LEN], ppow[LEN], P = 1993;
char s[LEN];
int n, N, a[250010];
double ans;

inline ull hash (int l, int r) {
	ull h = pr[r];
	if(l) h -= pr[l - 1];
	h *= ppow[LEN - l - 1];
	return h;
}

int lcp (int q, int p) {
	int l = 1, r = N, m;
	while (l <= r) {
		m = (l + r) / 2;
		if (hash(q, q + m - 1) == hash(p, p + m - 1))
			l = m + 1;
		else r = m - 1;
	}
	return l - 1;
}

bool cmp (int q, int p){
	int l = lcp(q, p);
	return (l < N && s[q + l] < s[p + l]);
}

/* START */
int main (){
	scanf("%d%s", &n, s);
	N = n;
	for (int i = 0; i < n; i++) 
		s[i + n] = s[i];
	n *= 2;
	ppow[LEN - 1] = 1;
	for (int i = LEN - 2; i >= 0; i--) 
		ppow[i] = ppow[i + 1] * P;
	for (int i = 0; i < n; i++) {
		pr[i] = ppow[i] * (s[i] - 'A' + 1);
		if (i) pr[i] += pr[i - 1];
	}
	for (int i = 0; i < N; i++) 
		a[i] = i;
	sort(a, a + N, cmp);
	for (int i = 1; i < N; i++)
		ans += (double)(lcp(a[i - 1], a[i]));
	ans /= (N - 1);
	printf("%.3lf\n", ans);
	return 0;
}
