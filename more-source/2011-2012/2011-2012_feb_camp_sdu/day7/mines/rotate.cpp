#include <cstdio>
#include <cstring>
int n, m;
char s[700][700];
int main() {
	while (~scanf("%s", s[n])) {
		m = strlen(s[n]);n++;
	}
	for (int i = 0; i < m; i++) {
		for (int j = n-1; j >= 0; j--)
			printf("%c", s[j][i]);
	printf("\n");
	}
}
