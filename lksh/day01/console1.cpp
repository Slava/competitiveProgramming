#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int pi[510], n, strl[120];
char s[510], T[120][510], boost[2];
bool kmp(char *p, char *t, int l) {
	s[0] = 0;
	strcat(s, p); strcat(s, boost); strcat(s, t);
	pi[0] = 0; int j = 0, len = strlen(s);
	for (int i = 1; i < len; i++) {
		while (j > 0 && s[j] != s[i])
			j = pi[j - 1];
		if (s[j] == s[i])
			j++;
		pi[i] = j;
		if (j == l)
			return 1;
	}
	return 0;
}


int main() {
	freopen("console1.in", "r", stdin);
	freopen("console1.out", "w", stdout);
	char s[510]; boost[0] = 20;
	scanf("%d", &n);gets(s);
	for (int i = 0; i < n; i++) {
		gets(T[i]);
		strl[i] = strlen(T[i]);
	}
	for (; gets(s); ) {
		bool was = 0;
		for (int i = 0; i < n && !was; i++)
			if (kmp(T[i], s, strl[i])) {
				was = 1;
				printf("%s\n", s);
			}
	}
	return 0;
}
