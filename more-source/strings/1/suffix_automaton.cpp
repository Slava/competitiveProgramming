#include <cstdio>
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

int main() {
	return 0;
}

//	~/lksh/day06/*
