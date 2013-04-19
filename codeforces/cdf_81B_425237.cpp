#include <cstdio>
#include <cstring>

char s[300], t[300], ans[500];
int n, m, mn;
int main (){
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	while(scanf("%s", t) == 1){
		strcat(s, t);strcat(s, " ");
	}
	n = strlen(s);
	for (int i = 0; i < n; i++){
		if (s[i] == ',')
			ans[m++] = ',', ans[m++] = ' ';
		else if (s[i] == '.'){
			if (m && ans[m - 1] != ' ' && mn == 0)
				ans[m++] = ' ';
			mn++; mn %= 3;
			ans[m++] = '.';
		}
		else if (s[i] == ' '){
			int cif = (m && ans[m - 1] >= '0' && ans[m - 1] <= '9');
			while (i < n && s[i] == ' ')i++;
			if (s[i] >= '0' && s[i] <= '9' && cif)
				ans[m++] = ' ', ans[m++] = s[i];
			else i--;
		}
		else ans[m++] = s[i];
	}
	bool was = 0;
	while (m && ans[m - 1] == ' ')m--;
	for (int i = 0; i < m; i++)
		if (was || ans[i] != ' '){
			printf("%c", ans[i]);
			was = 1;
		}
	return 0;
}






// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: May 4, 2011 9:32:35 AM
// contest: 81
// link: /contest/81/submission/425237
// time: 30 ms
// verdict: Accepted
// problem: 81B - Sequence Formatting
// ID: 425237
// downloaded by very stupid script
