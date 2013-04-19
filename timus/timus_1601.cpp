#include <cstdio>
#include <cstdlib>

char c;
int u = 1;
int main() {
	while (scanf("%c", &c) == 1) {
		if (c >= 'A' && c <= 'Z')
			if (u) {
				printf("%c", c);
				u = 0;
			}
			else printf("%c", c - 'A' + 'a');
		else if (c >= 'a' && c <= 'z')
			if (u) {
				printf("%c", c - 'a' + 'A');
				u = 0;
			}
			else printf("%c", c);
		else if (c == '.' || c == '!' || c == '?') {
			printf("%c", c); u = 1;
		}
		else printf("%c", c);
	}
	return 0;
}
