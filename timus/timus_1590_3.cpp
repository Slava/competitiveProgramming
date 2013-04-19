#include <cstdio>
#include <cstring>

// N must be twice bigger
const int N = 200001, K = 26;
int link[N][K], suff[N], len[N], nodesUsed, last;
#define conv(x) (x-'a')

void init() {
	memset(link, -1, sizeof link);
	memset(suff, -1, sizeof suff);

	nodesUsed = 1;
	len[0] = 0;
	last = 0;
}

void addChar(int ch) {
	int newv = nodesUsed++, v;
	len[newv] = len[last] + 1;

	for (v = last; v != -1 && link[v][ch] == -1; v = suff[v])
		link[v][ch] = newv;

	if (v == -1)		// 1
		suff[newv] = 0;
	else {
		int u = link[v][ch];
		if (len[v] + 1 == len[u])	// 2.a
			suff[newv] = u;
		else {						// 2.b
			int cl = nodesUsed++;
			for (int i = 0; i < K; i++)
				link[cl][i] = link[u][i];

			suff[cl] = suff[u];
			len[cl] = len[v] + 1;

			for (; v != -1 && link[v][ch] == u; v = suff[v])
				link[v][ch] = cl;

			suff[u] = suff[newv] = cl;
		}
	}

	last = newv;
}

void addString(char *s, int len) {
	for (int i=0; i<len; i++)
		addChar(conv(s[i]));
}
int main() {
	init();
	char s[20000];
	scanf("%s", s);

	addString(s, strlen(s));
	int ans = 0;
	for (int i = 1; i < nodesUsed; i++)
		ans += (len[i] - len[suff[i]]);

	printf("%d\n", ans);
	return 0;
}

