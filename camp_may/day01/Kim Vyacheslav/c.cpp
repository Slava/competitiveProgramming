#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

//#define debug

int k1, k2, n, m, h, w, a[101010], b[101010];
int N, M, A[101010], B[101010], ac[101010], bc[101010];
ll sum(int a, int b) {
	if (a == 1 && b == 1) return 1;
	if (a <= 0 || b <= 0) return 0;
	return (a * 1ll) * (b * 1ll);
}

ll sumint (int a, int b) {
	return sum(a - k1 * 2, b - k1 * 2) - sum(a - (k2 + 1) * 2, b - (k2 + 1) * 2);
}


ll ans;
int main() {
#ifndef debug
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	cin >> w >> h >> k1 >> k2 >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= m; i++)
		scanf("%d", b + i);
	n++; m++;a[n] = h; b[m] = w; 
/*	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			ans += sumint(a[i + 1] - a[i], b[j + 1] - b[j]);
#ifdef debug			
			cerr << a[i + 1] << " - " << a[i] <<"  " << b[j + 1] << " - " << b[j] << "\n";
#endif		
		}
*/
	for (int i = 0; i < n; i++)
		A[N++] = a[i + 1] - a[i];
	for (int i = 0; i < m; i++)
		B[M++] = b[i + 1] - b[i];
	sort(A, A + N);sort(B, B + M);
	n = m = 0;
	for (int i = 0; i < N; i++)
		if (!n || A[i] != A[i - 1])
			a[n] = A[i], ac[n++] = 1;
		else ac[n - 1]++;
	for (int j = 0; j < M; j++)
		if (!m || B[j] != B[j - 1])
			b[m] = B[j], bc[m++] = 1;
		else bc[m - 1]++;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			ans += sumint(a[i], b[j]) * ((1ll * ac[i]) * (1ll * bc[j]));
	cout << ans;
	return 0;
}

