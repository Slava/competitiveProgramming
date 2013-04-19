#include <cstdio>

int d[] = {2,1,1,2,-1,2,-2,1,1,-2,2,-1,-1,-2,-2,-1},
	n, x, y, X, Y, ans;
char s[5];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		ans = 0;
		x = s[0] - 'a' + 1;
		y = s[1] - '0';
		for (int j = 0; j < 16; j += 2) {
			X = x + d[j]; Y = y + d[j + 1];
			ans += (X > 0 && X < 9 && Y > 0 && Y < 9);
		}
		printf("%d\n", ans);
	}
	return 0;
}

