#include <cstdio>

int main (){
	int t;
	scanf("%d", &t);
	double a, b, ans;
	for (int i = 0; i < t; i++){
		scanf("%lf%lf", &a, &b);
		if (!a && !b)
			ans = 1;
		else if (!a)
			ans = 0.5;
		else if (!b)
			ans = 1;
		else if (4*b > a){
			ans = a*a/8. + (b - a/4.) * a;
			ans = 2*b*a - ans;
			ans = ans / 2. / b / a;
		}
		else{
			ans = b*b*2;
			ans = a*b*2 - ans;
			ans = ans / a / b / 2.;
		}
		printf("%lf\n", ans);
	}
	return 0;
}





// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Apr 25, 2011 5:51:36 PM
// contest: 80
// link: /contest/80/submission/407498
// time: 50 ms
// verdict: Accepted
// problem: 80D - Falling Anvils
// ID: 407498
// downloaded by very stupid script
