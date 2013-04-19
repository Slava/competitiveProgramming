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





// lang: GNU C++
// memory: 1700 KB
// author: imslavko
// submit_date: May 4, 2011 9:09:35 AM
// contest: 81
// link: /contest/81/submission/423841
// time: 50 ms
// verdict: Accepted
// problem: 81A - Plug-in
// ID: 423841
// downloaded by very stupid script
