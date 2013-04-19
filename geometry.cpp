#include <cstdio>
#include <cmath>
#include <algorithm>
#define abs(x) ((x)<0?-(x):(x))

using namespace std;

const double PI = acos(-1.0);
typedef double T;
// point and vector
struct pt{
	T x, y;
	pt () { x = y = 0;}
	pt (T _, T __) {	x = _; y = __;	}
	T d ()	{	return sqrt(x*x + y*y);	}
	T operator () (pt b){	return x*b.x + y*b.y;	}
	T operator [] (pt b){	return x*b.y - b.x*y;	}
};
pt point(T _, T __){
	pt a; a.x = _; a.y = __;
	return a;
}
pt operator + (pt a, pt b){	return point(a.x + b.x, a.y + b.y);	}
pt operator - (pt a, pt b){	return point(a.x - b.x, a.y - b.y);	}
pt operator + (pt a, T x){	return point(a.x + x, a.y + x);	}
pt operator * (pt a, T x){	return point(a.x * x, a.y * x);	}
bool operator < (pt a, pt b){	return a[b] > 0 || (a[b] == 0 && a.d() < b.d());	}

template <class TT>
void dotsToLine(pt a, pt b, TT &A, TT &B, TT &C){
	A = a.y - b.y;	B = b.x - a.x;
	C = - a.y*(b.x - a.x) - a.x*(a.y - b.y);
}

pt z(0,0);
int main ()
{
	pt a(2, 2);
	a = a * (1/a.d());
	pt b = a;b.x = -b.x;
	printf("%lf", b[a]);
}

