#include <cstdio>
#include <cstdlib>

int min(int i, int j) {
	return i < j ? i : j;
}

int a[100100], d[100100][2], n, j;
int main() {
	scanf("%d%d", &j, &n);
	n = n - j + 1; j = 1;
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	for (int i = 1; i < n; i++) {
		if (a[i] != a[j - 1])
			a[j++] = a[i];
	}
	n = j;
	d[0][0] = d[0][1] = 1;
	for (int i = 1; i < n; i++) {
		if (a[i - 1] < a[i]) {
			d[i][0] = min(d[i - 1][0], d[i - 1][1] + 1);
			d[i][1] = min(d[i - 1][1] + 1, d[i - 1][0] + 1);
		}
		else {
			d[i][0] = min(d[i - 1][0] + 1, d[i - 1][1] + 1);
			d[i][1] = min(d[i - 1][1], d[i - 1][0] + 1);
		}
	}
	printf("%d\n", min(d[n - 1][0], d[n - 1][1]));
	return 0;
}
