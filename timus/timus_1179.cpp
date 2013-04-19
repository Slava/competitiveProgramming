#include <cstdio>
#include <cstdlib>
#include <cstring>

char s[100100];
int n, c[40];
int main() {
	while(scanf("%s", s) == 1) {
		n = strlen(s); 
		for (int i = 0; i < n; i++)
			if (s[i] <= '9')
				s[i] -= '0';
			else s[i] -= 'A' - 10;
		for (int k = 2; k <= 36; k++) {
			int i = 0, l = 0;
			for (; i < n; i++) {
				if (s[i] >= k) {
					if (l)c[k]++;
					l = 0;
					continue;
				}
				l++;
			}
			if (l) 
				c[k]++;
		}
		memset(s, 0, sizeof s);
	}
	int m = 0;
	for (int i = 2; i < 37; i++)
		if (c[i] > c[m])
			m = i;
	printf("%d %d\n", m, c[m]);
	return 0;
}
