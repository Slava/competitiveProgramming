#include <cstdio>

int n; 
double p[200], a[200][2];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lf", p + i);
	a[0][0] = p[0]; a[0][1] = 1 - p[0];
	for (int i = 1; i < n; i++) {
		a[i][0] = a[i - 1][1] * (1 - p[i]) + a[i - 1][0] * p[i]; 
		a[i][1] = a[i - 1][0] * (1 - p[i]) + a[i - 1][1] * p[i];
	}
	
	printf("%.10lf\n", a[n - 1][0]);

	return 0;
}
