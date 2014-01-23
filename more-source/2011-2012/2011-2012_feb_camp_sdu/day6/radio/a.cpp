#include <cstdio>

int pi[10005000], n, j;
char s[10005000];

int main() {
	scanf("%d%s", &n, s);
	for (int i = 1; i < n; i++) {
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])
			j++;
		pi[i] = j;
	}
	
	printf("%d\n", n-pi[n-1]);

	return 0;
}

