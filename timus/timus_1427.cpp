#include <cstdio>
#include <cstdlib>
#include <cstring>

bool isalpha(char c) {
	return c == ' ' || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

char s[100100];
int n, N, M, t, c, mod;
int main() {
	gets(s); sscanf(s, "%d%d", &N, &M);
	gets(s); n = strlen(s);
	for (int i = 0; i < n; i++) {
		if (isalpha(s[i])) {
			t++; 
		}
		else {
			if (!mod && t + 1 <= N) {
				mod = 1; t++; 
			}
			else if (!mod && t + 1 > N) {
				mod = 1; t = 1; c++;
			}
			else if (mod) t++;
		}
		if ((!mod && t == M) || (mod && t == N)) {
			t = 0; mod = 0; c++;
		}
	}
	if (t) c++;
	printf("%d\n", c);
	return 0;
}
