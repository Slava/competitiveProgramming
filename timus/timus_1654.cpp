#include <cstdio>
#include <cstring>

char s[201000],
	a[201000];
int n, m;
int main (){
	scanf("%s", s);
	n = strlen(s);
	a[m] = s[0];
	for (int i = 1; i < n; ){
		if (m >= 0 && a[m] == s[i]){
			i++; m--;
		}else{
			a[++m] = s[i++];
		}
	}
	for (int i = 0; i <= m; i++)
		printf("%c", a[i]);
}

