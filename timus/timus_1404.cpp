#include <cstdio>
#include <cstring>

char s[200];
int n;
int main() {
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; i++)
		s[i] -= 'a';
	for (int i = n - 1; i > 0; i--)
		s[i] = (s[i] - s[i - 1] + 26) % 26;
	s[0] = (s[0] - 5 + 26) % 26;
	for (int i = 0; i < n; i++)
		printf("%c", s[i] + 'a');
	return 0;
}

