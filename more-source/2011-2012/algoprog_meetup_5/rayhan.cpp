#include <cstdio>
#include <cstdlib>
#include <cstring>

int a[256][256], n = 256;
char s[100010], t[20];
int m, len;

int main() {
	freopen("rayhan.in", "r", stdin);
	freopen("rayhan.out", "w", stdout);
	scanf("%s", s); len = strlen(s);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%s", t);
		a[t[0]][t[1]] = a[t[1]][t[0]] = 1;
	}
	if (len & 1) {
		puts("NO");
		return 0;
	}
	for (int i = 0; i < len; i += 2)
		if (!a[s[i]][s[i + 1]]) {
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}
