#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main ()
{
	double a, v, l, d, w, t, 
		   v1, v2, v3, ans, s;
	scanf ("%lf%lf%lf%lf%lf", &a, &v, &l, &d, &w);
	v1 = min(min(w, v), sqrt(2 * a * d));
	t = ans = v1 / a;

	s = d - a * t * t / 2;
	v2 = sqrt(s * a + v1 * v1);

	if (v2 <= v) ans += 2 * (v2 - v1) / a;
	else ans += 2 * (v - v1) / a + (s - (v * v - v1 * v1) / a) / v;

	s = l - d;
	v3 = sqrt(2 * a * s + v1 * v1);

    if (v3 <= v) ans += (v3 - v1) / a;
    else ans += (v - v1) / a + (s - 0.5 * (v * v - v1 * v1) / a) / v;

	printf("%.5lf\n", ans);

	return 0;
}





// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Feb 20, 2011 5:15:40 PM
// contest: 5
// link: /contest/5/submission/292690
// time: 30 ms
// verdict: Accepted
// problem: 5D - Follow Traffic Rules
// ID: 292690
// downloaded by very stupid script
