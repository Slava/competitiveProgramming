#include <cstdio>
#include <cstring>

char s[20100], t[20100];
int n, m, pi[20100], j, i;
int main (){
	scanf("%s", s);
	memcpy(t, s, sizeof s);
	m = n = strlen(s);
	for (i = 0; i < n; i++)
		s[n + i] = s[i];
	for (i = 0; i < n; i++)
		s[i] = s[n + n - i - 1];
	s[n] = '$';
	n = n + n;
	for (i = 1; i < n; i++){
		while (j > 0 && s[j] != s[i])
			j = pi[j - 1];
		if (s[i] == s[j])
			j++;
		pi[i] = j;
	}
	for (i = 0; i < m; i++)
		printf("%c", t[i]);
	for (i = j; i < m; i++)
		printf("%c", s[i]);
	return 0;
}

