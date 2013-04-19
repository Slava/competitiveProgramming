#include <cstdio>
#include <cmath>
#define abs(x) (x<0?-(x):x)

int g[35], n, m;
int ggt (int i){
	if (i <= 0) return 0;
	if (g[i])return g[i];
	return g[i] = 
	ggt(i - 1) * 2 + i + i - 2;
}

int get (int n){
	if (n == 1) return 0;
	int i = log(n+.0)/log(2.), 
		k = n - (1 << i);
	return i - 1 + ggt(i - 1) + ( k ? get(k) + i - 1 : 0);
}

int main (){
	scanf("%d%d", &n, &m);
	printf("%d\n", abs(get(n) - get(m)));
	return 0;
}

