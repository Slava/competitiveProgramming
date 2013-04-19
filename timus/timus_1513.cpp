#include <cstdio>

struct bigint{
	int a[340], n;
	bigint(){n = 1;}
	int &operator [] (int i){
		return a[i];
	}
	void print(){
		printf("%d", a[n - 1]);
		for (int i = n - 2; i >= 0; i--)
			printf("%09d", a[i]);
	}
}d[11000];

bigint operator * (bigint a, int b){
	long long c = 0, t;
	for (int i = 0; i < a.n || c; i++){
		if (a.n < i + 1)
			a.n = i + 1;
		t = 1ll * a[i] * b + c;
		c = t / 1000000000ll;
		a[i] = (t - c * 1000000000ll);
	}
	return a;
}

bigint operator - (bigint a, bigint b){
	int c = 0;
	for (int i = 0; i < a.n; i++){
		a[i] = a[i] - b[i] - c;
		if (a[i] < 0){
			a[i] += 1000000000;
			c = 1;
		}else c = 0;
	}
	while(a.n > 1 && !a[a.n - 1])a.n--;
	return a;
}

int n, k;
int main (){
	scanf("%d%d", &n, &k);
	if (!k){puts("1");return 0;}
	d[0][0] = d[1][0] = 1;
	for (int i = 2; i <= k + 1; i++)
		d[i] = d[i - 1] * 2;
	for (int i = k + 2; i <= n + 1; i++)
		d[i] = d[i - 1] * 2 - d[i - 2 - k];
	d[n + 1].print();
	return 0;
}

