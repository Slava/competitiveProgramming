#include <cstdio>
#include <cstring>
#define max(a,b) (a>b?a:b)

int a[200], A[200], sum, answer;
int dp[200][200], pr[200];

int play(int n) {
//	for (int i = 0; i < n; i++)
//		printf("%d ", A[i]); 
	memset(dp, 0, sizeof dp);
	for (int i = 0; i < n; i++) {
		pr[i] = dp[i][i] = A[i];
		if (i) pr[i] += pr[i-1];
	}
	for (int i = 1; i < n; i++)
		for (int j = 0; j+i < n; j++) {
			int l = j, r = i+j;
			dp[l][r] = max(A[l]+(pr[r]-pr[l])-dp[l+1][r],
							A[r]+(pr[r-1]-(l?pr[l-1]:0))-dp[l][r-1]);
		}
//	printf(":%d\n", dp[0][n-1]);
	return dp[0][n-1];
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i] %= 2;
		sum += a[i];
	}

	for (int i = 0; i < n; i++) {
		int k = 0;
		for (int j = i+1; j < n; j++)
			A[k++] = a[j];
		for (int j = 0; j < i; j++)
			A[k++] = a[j];
		int zvonko = play(n-1), ivana = sum - zvonko;
		if (ivana > zvonko)
			answer++;
	}

	printf("%d\n", answer);

	return 0;
}

