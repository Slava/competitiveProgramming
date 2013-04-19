#include <cstdio>
#include <cstdlib>
#include <cstring>

const int SIGMA = 26;
const int MAXLEN = 1000000 * 4;
struct node {
	int len; bool end;
	node *suff, *link[SIGMA];
	node (int l) {
		len = l; suff = 0; end = 0;
		memset(link, 0, sizeof link);
	}
} root(0), *last = &root;

void add_char(int C) {
	node *newl = new node(last->len + 1);
	node *v = last;
	for (; v && !v->link[C]; v = v->suff)
		v->link[C] = newl;
	if (v) {
		node *q = v->link[C];
		if (q->len == v->len + 1)
			newl->suff = q;
		else {
			node *clone = new node(v->len + 1);
			memcpy(clone->link, q->link, sizeof q->link);
			clone->suff = q->suff;
			for (; v && v->link[C] == q; v = v->suff)
				v->link[C] = clone;
			q->suff = newl->suff = clone;
		}
	}
	else newl->suff = &root;
	last = newl;
}

inline int conv(char c) {
	if (c < 'a')
		return c - 'A';
	return c - 'a';
}

void add_string(char *s, int len) {
	for (int i = 0; i < len; i++)
		add_char(conv(s[i]));
}

void mark() {
	for (node *v = last; v; v = v->suff)
		v->end = 1;
}

char s[MAXLEN], ans[MAXLEN];
int n, k, le;
int main() {
	scanf("%s", s);
	add_string(s, strlen(s));
	scanf("%d", &k);
	for (int j = 0; j < k; j++) {
		le = 0; bool ok = 1;
		scanf("%s", s); n = strlen(s);
		node *v = &root;
		for (int i = 0; i < n; i++) {
			int g = conv(s[i]);
			if (!v->link[g])
				if (v == &root) {
					ok = 0; break;
				}
				else {
					ans[le++] = '|';
					i--;
					v = &root;
				}
			else {
				ans[le++] = s[i];
				v = v->link[g];
			}
		}
		if (le && ans[le - 1] == '|')le--;
		if (!ok)
			printf("NO");
		else for (int i = 0; i < le; i++)
			printf("%c", ans[i]); printf("\n");
	}
	return 0;
}

