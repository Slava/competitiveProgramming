#include <cstdio>

int t[32100], n = 32001;
int x, y, m, l[15100];

void inc (int i){
	for (; i < n; i |= (i + 1))
		t[i]++;
}

int sum (int i){
	int r = 0;
	for (; i >= 0; i &= (i + 1), i--)
		r += t[i];
	return r;
}

int main (){
	scanf("%d", &m);
	for (int i = 0; i < m; i++){
		scanf("%d%d", &x, &y);
		l[sum(x)]++;
		inc(x);
	}
	for (int i = 0; i < m; i++)
		printf("%d\n", l[i]);
	return 0;
}

