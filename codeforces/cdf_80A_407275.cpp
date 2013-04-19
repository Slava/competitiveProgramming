#include <cstdio>

bool isprime (int x){
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

int main (){
	int a, b, c = 0;
	scanf("%d%d", &a, &b);
	for (int i = a + 1; i < b; i++)
		c += isprime(i);
	if (!c && isprime(b))
		puts("YES");
	else puts("NO");
	return 0;
}





// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Apr 25, 2011 10:14:09 AM
// contest: 80
// link: /contest/80/submission/407275
// time: 30 ms
// verdict: Accepted
// problem: 80A - Panoramixs Prediction
// ID: 407275
// downloaded by very stupid script
