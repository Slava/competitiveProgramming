#include <cstdio>
#include <cstdlib>
#include <ctime>

int n, cnt, was[5002], m, st[5002], sz, start;
char s[5002][5002];

void dfs(int v) {
	if (was[v] == 2)
		return;
	
	if (was[v] == 1) {
		for (int i = 0; i < sz; i++)
			if (st[i] == v)
				start = i;
		for (int i = 0; i + start < sz; i++)
			st[i] = st[i + start];
		sz -= start;
		while (sz > 3 && s[st[0]][st[sz - 2]] != '1')
			sz--;
		printf("%d %d %d\n", st[sz - 1] + 1, st[0] + 1, st[sz - 2] + 1);
		exit(0);
	}

	was[v] = 1; st[sz++] = v;
	for (int i = 0; i < n; i++)
		if (s[v][i] == '1')
			dfs(i);
	was[v] = 2; sz--;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);
	for (int i = 0; i < n; i++)
		dfs(i);
	printf("-1\n");	

	return 0;
}




// lang: MS C++
// memory: 26000 KB
// author: imslavko
// submit_date: Sep 23, 2011 10:18:15 PM
// contest: 117
// link: /contest/117/submission/720103
// time: 360 ms
// verdict: Accepted
// problem: 117C - Cycle
// ID: 720103
// downloaded by very stupid script
