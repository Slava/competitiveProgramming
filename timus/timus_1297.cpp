#include <cstdio>
#include <cstring>
#define min(a,b) (a<b?a:b)

char s[1010];
int n, d[1010], w[1010], l, r;
int main (){
	scanf("%s", s);
	n = strlen(s);
	r = -1;
	for (int i = 0; i < n; i++){
		if (i <= r)
			d[i] = min(d[l + r - i], r - i);
		for (; i + d[i] + 1 < n && i - d[i] - 1 >= 0 && 
				s[i + d[i] + 1] == s[i - d[i] - 1];) d[i]++;
		if (r < i + d[i]){
			l = i - d[i];
			r = i + d[i];
		}
	}
	r = -1;
	for (int i = 0; i < n; i++){
		if (i <= r)
			w[i] = min(w[l + r - i + 1], r - i + 1);
		for (; i + w[i] < n && i - w[i] - 1 >= 0 &&
			s[i + w[i]] == s[i - w[i] - 1];)w[i]++;
		if (r < i + w[i]){
			l = i - w[i];
			r = i + w[i] - 1;
		}
	}
	int mn, mx;mn = mx = 0;
	for (int i = 0; i < n; i++)
		if (d[i] > d[mn])
			mn = i;
	for (int i = 0; i < n; i++)
		if (w[i] > w[mx])
			mx = i;
	if (d[mn] * 2 + 1 > w[mx] * 2)
		for (int i = mn - d[mn]; i <= d[mn] + mn; i++)
			printf("%c", s[i]);
	else for (int i = mx - w[mx]; i < w[mx] + mx; i++)
			printf("%c", s[i]);
	return 0;
}

