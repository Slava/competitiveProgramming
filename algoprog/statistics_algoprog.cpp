#include <cstdio>
#include <cstring>

char s[10100];
int a[26];
int main (){
	freopen("statistics.in", "r", stdin);
	freopen("statistics.out", "w", stdout);
	while(scanf("%s", s) == 1){	
	int n = strlen(s);
	for (int i = 0; i < n; i++){
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += - 'A' + 'a';
		if (s[i] >= 'a' && s[i] <= 'z')
			a[s[i] - 'a']++;
	}
	}
	for (int i = 'A'; i <= 'Z'; i++)
		printf("%c - %d\n", i, a[i - 'A']);

	return 0;
}

