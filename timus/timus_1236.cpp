#include <cstdio>
#include <cstdlib>
#include <cstring>

char s[20100], x[20100];
char en[] = "0123456789ABCDEF";
int m[20100], k[20100], a[20100];

void make(char s[], int a[]) {
	int n = strlen(s);
	n /= 2;
	for (int i = 0, j = 0; i < n; i++) {
		int x;
		if (s[j] >= '0' && s[j] <= '9')
			x = s[j] - '0';
		else x = s[j] - 'A' + 10;
		x *= 16; j++;
		if (s[j] >= '0' && s[j] <= '9')
			x += s[j] - '0';
		else x += s[j] - 'A' + 10;
		a[i] = x; j++;
	}
}

int main() {
	scanf("%s%s", s, x);
	make(s, m); make(x, k);
	int n = strlen(s) / 2, pr = 32, xr;
	for (int i = 0; i <= n; i++) {
		xr = pr ^ k[i];
		pr = xr ^ m[i];
		printf("%c%c", en[xr / 16], en[xr % 16]);
	}
	return 0;
}
