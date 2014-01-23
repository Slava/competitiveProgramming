#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

char s[200];
long long  dp[200][26];
void solve() {
	scanf("%s", s);
	int n = strlen(s);
	long long sum = 1;
	for (int i = 0; i < n; i++)
		s[i] -= 'a';
	for (int i = 1; i < n; i++)
		sum += s[i];
	printf("%Ld\n", sum);
}


int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
		solve();

	return 0;
}

