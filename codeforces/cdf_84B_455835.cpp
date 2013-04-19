#include <cstdio>
#include <cstdlib>

int n, a[101010];
int j;
long long ans;
/* START */
int main (){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	for (int i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			if (a[j] != a[i])
				break;
		}
		ans += ((j * 1ll - i * 1ll)*(j * 1ll - i * 1ll + 1ll)/2ll);
		i = j - 1;
	}
	printf("%I64d\n", ans);
	return 0;
}




// lang: GNU C++
// memory: 1700 KB
// author: imslavko
// submit_date: May 15, 2011 12:37:45 PM
// contest: 84
// link: /contest/84/submission/455835
// time: 60 ms
// verdict: Accepted
// problem: 84B - Magical Array
// ID: 455835
// downloaded by very stupid script
