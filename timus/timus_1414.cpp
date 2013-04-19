#include <cstdio>
#include <cstdlib>
#include <cstring>

const int N = 1001001;
struct node {
	node *l, *r, *m;
	bool leaf;
	char c;
	node(char _) {
		c = _;
		leaf = 0;
		l = r = m = 0;
	}
	node(){}
}buff[N];
int buffSize;

node *new_node(char _) {
	buff[buffSize] = node(_);
	return buff+buffSize++;
}

node *root;

void add_string(char *s) {
	node **v = &root;
	int len = strlen(s);

	for (int i = 0; i < len; i++) {
		while ((*v) && (*v)->c != s[i])
			if (s[i] < (*v)->c)
				v = &(*v)->l;
			else
				v = &(*v)->r;
		
		if (!(*v)) (*v) = new_node(s[i]);
		if (i != len-1)v = &(*v)->m;
		else (*v)->leaf = 1;
	}
}

int cnt, sz;
char st[N];

void out(node *v) {
	if (!cnt || !v)return;
	out(v->l);
	st[sz++] = v->c;
	if (cnt && v->leaf) {
		st[sz] = 0;
		printf("  %s\n", st);
		cnt--;
	}
	out(v->m);
	sz--;
	out(v->r);
}

void printLex(char *s, int num) {
	printf("%s\n", s);
	cnt = num;
	node *v = root;
	int len = strlen(s);
	sz = len;
	strcpy(st, s);

	for (int i = 0; i < len; i++) {
		while (v && v->c != s[i])
			if (v->c > s[i])
				v = v->l;
			else v = v->r;
		if (!v)
			return;
		if (i == len-1 && v->leaf)
			printf("  %s\n", s);
		v = v->m;
	}
	out(v);
}

char query[N];
int main() {
	add_string("sun");
	while(gets(query)) {
		if (query[0] == '+')
			add_string(query+1);
		else
			printLex(query+1, 20);
	}
	return 0;
}
