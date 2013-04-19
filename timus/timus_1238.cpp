#include <cstdio>
#include <cstdlib>
#include <cstring>
#define min(a,b) (a<b?a:b)

int pi[110];
int prefix (char s[], int n){
	int j = 0, ans = 0;
	for (int i = 1; i < n; i++){
		while(j > 0 && s[j] != s[i])
			j = pi[j - 1];
		if (s[i] == s[j])
			j++;
		pi[i] = j;
	}
	if (n - j <= j){
		ans = n - j;
		if (n % ans != 0)
			ans = 0;
	}
	return ans;
}

int num(int n){
	return n < 10 ? 1 : 2;
}

int a[102][102], n, pre[102][102];
char s[102];

void out(int l, int r){
	if (a[l][r] == r - l + 1){
		for (int i = l; i <= r; i++)
			printf("%c", s[i]);
		return ;
	}
	for (int i = l; i < r; i++)
		if (a[l][r] == a[l][i] + a[i + 1][r]){
			out(l, i); out(i + 1, r);
			return ;
		}
	if (pre[l][r])
	if (a[l][r] == num((r - l + 1) / pre[l][r]) + 2 + a[l][l + pre[l][r] - 1]){
		printf("%d(", (r - l + 1) / pre[l][r]);out(l, l + pre[l][r] - 1);
		printf(")");
		return ;
	}
	fprintf(stderr, "unexpected end of func out(%d,%d)\n", l, r);
	exit(1);
}

int main (){
	scanf("%s", s);
	n = strlen(s);
	for (int j = 0; j < n; j++) 
		for (int i = 0; i + j < n; i++)
			if (j < 4)a[i][i + j] = j + 1;else{
			int r = i + j, pr;
			a[i][r] = j + 1;
			for (int k = i; k < r; k++)
				a[i][r] = min(a[i][r], a[i][k] + a[k + 1][r]);
			pre[i][r] = pr = prefix(s + i, j + 1);
			if (pr){
				int k = (j + 1) / pr;
				a[i][r] = min(a[i][r], a[i][i + pr - 1] + 2 + num(k));
			}
		}
	out(0, n - 1);
	return 0;
}
