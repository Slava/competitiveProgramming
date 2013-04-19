#include <cstdio>

typedef long long Int;

#define abs(x) (x<0?-(x):x)
#ifdef WIN
#define i64 "%I64d"
#else
#define i64 "%Ld"
#endif

const int N = 110;
Int x[N], y[N], X, Y;
int n, m;

Int area(Int x1, Int y1, Int x2, Int y2, Int x3, Int y3) {
	return abs((x1-x3)*(y2-y3)-(x2-x3)*(y1-y3));
}

int main() {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf(i64 i64, x+i, y+i);
	Int polygon = 0;
	for (int i = 2; i < n; i++)
		polygon += area(x[0],y[0],x[i-1],y[i-1],x[i],y[i]);

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		bool ok = 1;
		for (int j = 0; j < 2; j++) {
			scanf(i64 i64, &X, &Y);
			Int ar = 0;
			for (int k = 0; k < n; k++)
				ar += area(X,Y,x[k],y[k],x[(k+1)%n],y[(k+1)%n]);
			ok &= (ar == polygon);
		}
		puts(ok ? "YES" : "NO");
	}

	return 0;
}
