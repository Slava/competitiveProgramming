#include <cstdio>

int n, k, f[50] = {1, 2}, a[50];
int main (){
	scanf("%d%d", &n, &k); 
	for (int i = 2; i <= n; i++)
		f[i] = f[i - 1] + f[i - 2];
	if (f[n] < k){printf("-1");return 0;}
	for (int i = 1; i <= n; i++){
		int x = f[n - i];
		if (k > x){
			a[i] = 1;
			i++; k -= x;
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d", a[i]);
	return 0;
}

