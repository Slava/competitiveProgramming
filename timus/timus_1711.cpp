#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct node {
	string s[3];
	int i;
}a[20];
int b[20];

bool cmp(int i, int j) {
	return a[i].i < a[j].i;
}

int n, st[20], ts[20], ss, tt, was[20][3];
void dfs(int v) {
	if (v == n) {
		for (int i = 0; i < ss; i++)
			printf("%s\n", a[st[i]].s[ts[i]].c_str());
		exit(0);
	}
	for (int i = 0; i < 3; i++)
		if (!v || a[b[v]].s[i] >= a[st[ss - 1]].s[ts[tt - 1]]) {
			if (was[v][i])continue;
			was[v][i] = 1;
			st[ss++] = b[v]; ts[tt++] = i;
			dfs(v + 1);
			ss--;tt--;
		}
}

char buff[30];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%s", buff);
			a[i].s[j] = buff;
		}
		sort(a[i].s, a[i].s + 3);
		b[i] = i;
	}
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		a[x - 1].i = i;
	}
	sort(b, b + n, cmp);
	dfs(0);
	printf("IMPOSSIBLE");
	return 0;
}
