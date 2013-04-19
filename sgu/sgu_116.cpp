#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std; 

const int N = 20000;
bool np[N];
int n, k, p[N], sp[N], kk;
int ks[N], fr[N], u[N], inf = 1<<30;

void f(int n) {
	if (!n) {
		ks[n] = 0;
		return;
	}
	ks[n] = inf;
	u[n] = 1;
	for (int i = 0; i < kk; i++)
		if (sp[i] <= n) {
			if (!u[n-sp[i]])f(n-sp[i]);
			if (ks[n-sp[i]] + 1 < ks[n]) {
				ks[n] = ks[n-sp[i]] + 1;
				fr[n] = sp[i];
			}
		}
}

int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
		if (!np[i]) {
			p[k++] = i;
			for (int j = i + i; j <= n; j += i)
				np[j] = 1;
		}

	for (int i = 0; i < k; i++)
		if (p[i] <= k)
			sp[kk++] = p[p[i]-1];
	

	for (int i = 1; i <= n; i++)
		ks[i] = inf;
	f(n);
	if (ks[n] == inf) {
		puts("0");
		return 0;
	}
	printf("%d\n", ks[n]);
	
	k = 0;
	while (fr[n]) {
		p[k++] = fr[n];
		n = n-fr[n];
	}

	sort(p,p+k);
	reverse(p,p+k);
	for (int i = 0; i < k; i++)
		printf("%d ", p[i]);
	puts("");

	return 0;
}
