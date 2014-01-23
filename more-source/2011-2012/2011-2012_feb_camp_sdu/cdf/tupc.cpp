#include <cstdio>
#include <cstring>

char s[200];

long long ans = 0;
int n;

void dfs(int v, char c) {
	if (v == n-1) {
		ans++;
		puts(s);
	}
	else {
		for (int i = -25; i < 26; i++) 
			if (c + i >= 'a' && c+i <= 'z' && s[v+1] -i >= 'a' && s[v+1] - i <= 'z') {
				s[v+1]-=i;
				s[v] += i;
				dfs(v+1,s[v+1]-i);
				s[v+1]+=i;
				s[v] -= i;
			}
	}
}

int main() {
	scanf("%s", s);
	n =strlen(s);
	dfs(0, s[0]);
	printf("%lld\n", ans);
}
