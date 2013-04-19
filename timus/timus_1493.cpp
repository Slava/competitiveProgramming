#include <cstdio>
#define abs(x) (x<0?-(x):x)

char s[7];
int a, b, c, d, e;
int main() {
	scanf("%d", &c);
	sprintf(s, "%06d", c + 1);
	a = s[0] + s[1] + s[2];
	b = s[3] + s[4] + s[5];
	sprintf(s, "%06d", c - 1);
	e = s[0] + s[1] + s[2];
	d = s[3] + s[4] + s[5];
	printf("%s\n", !abs(a - b) || !abs(d - e) ? "Yes" : "No");
	return 0;
}

