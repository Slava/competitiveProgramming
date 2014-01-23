#include <cstdio>
#include <cstring>

void z_func(char *s, int *z) {
	int n = strlen(s), j, l, r;
	z[0] = 0; l = r = 0;
	for (int i = 1; i < n; i++) {
		if (i > r) z[i] = 0;
		else {
			j = i - l;
			if (z[j] + j <= z[l])
				z[i] = z[j];
			else z[i] = r - i + 1;
		}
		while (i + z[i] < n && s[i + z[i]] == s[z[i]])
			z[i]++;
		if (i + z[i] > r)
			l = i, r = i + z[i] - 1;
	}
}

char s[200000];
int z[20000], n;
int main() {
	scanf("%s", s); n = strlen(s);
	z_func(s, z);
	for (int i = 0; i < n; i++)
		printf("%d ", z[i]);
	return 0;
}

