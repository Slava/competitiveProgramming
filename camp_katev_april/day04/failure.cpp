#include <cstdio>
#define abs(x) ((x)<0?-(x):(x))
bool solve ()
{
	double v1, v2, l1, l2, x1, x2, y1, y2;
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf", 
		&v1, &v2, &l1, &l2, &x1, &x2, &y1, &y2);
	if (v1 == 0 || v2 == 0)
		return 0;
	double t1 = abs(x1 + y1) / v1,
		   t2 = abs(x2 + y2),
		   e1 = (abs(x1 + y1) + l1) / v1,
		   e2 = (abs(x2 + y2) + l2) / v2;
	return (t1 == t2 || (t1 >= t2 && t1 < e2) || (t2 >= t1 && t2 > e2));
}

int main ()
{
	freopen("failure.in", "r", stdin);
	freopen("failure.out", "w", stdout);
	
	int t;
	scanf("%d", &t);
	while (t--)
		printf("%d", solve());
	
	return 0;
}

