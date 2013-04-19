#include <cstdio>
typedef long long ll;
#define i64 "%I64d"

ll xorf (ll r){
	if (r % 4 == 1)
		return 1;
	if (r % 4 == 2)
		return r + 1;
	if (r % 4)
		return 0;
	return r;
}

int n;
ll ans, x, m;
int main ()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf(i64 i64, &x, &m);
		ans ^= xorf(x - 1);
		ans ^= xorf(x + m - 1);
	}
	puts(ans ? "tolik" : "bolik");
	return 0;
}





// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Apr 22, 2011 6:10:42 AM
// contest: 15
// link: /contest/15/submission/405188
// time: 160 ms
// verdict: Accepted
// problem: 15C - Industrial Nim
// ID: 405188
// downloaded by very stupid script
