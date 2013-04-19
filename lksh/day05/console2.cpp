#include <cstdio>
#include <cstring>
#include <cassert>

const int Sigma = 95;
const int LEAST = 32;
const int NODES = 83100;
struct node{
	node *next[Sigma], *go[Sigma], *fail, *p, *last;
	int pch; bool leaf;
	node (){
		leaf = 0;
		last = p = fail = 0;
		memset(next, 0, sizeof next);
		memset(go, 0, sizeof go);
	}
}root, Nodes[NODES];
int MM;
char s[80100];
int len;

node *New() {
	assert (MM < NODES);
	return &Nodes[MM++];
}

void add_string (char *str, int sz){
	node *v = &root;
	for (; sz--; str++){
		int l = *str - LEAST;
		assert(l < Sigma);
		if (!v->next[l]){
			v->next[l] = New();
			v->next[l]->p = v;
			v->next[l]->pch = l;
		}
		v = v->next[l];
	}
	v->leaf = 1;
}

node *go (node *v, int ch);
node *get_link (node *v){
	if (!v->fail)
		if (v == &root || v->p == &root)
			v->fail = &root;
		else v->fail = go(get_link(v->p), v->pch);
	return v->fail;
}

node *go (node *v, int ch){
	if (!v->go[ch])
		if (!v->next[ch])
			v->go[ch] = v == &root ? &root : go(get_link(v), ch);
		else v->go[ch] = v->next[ch];
	return v->go[ch];
}

node *get_last (node *v){
	if (!v->last)
		if (v == &root)
			v->last = v;
		else if (get_link(v)->leaf)
			v->last = get_link(v);
		else v->last = get_last(get_link(v));
	return v->last;
}

char t[1024 * 1025];
int main (){
	int n; 
	scanf("%d", &n);gets(t);
	for (int i = 0; i < n; i++){
		gets(s);
		add_string(s, len = strlen(s));
	}
	bool was;
	while (gets(t)) {
		int sz = strlen(t);node *v = &root;
		was = 0;
		for (int i = 0; i < sz; i++){
			if (v->next[t[i] - LEAST])
				v = v->next[t[i] - LEAST];
			else v = go(v, t[i] - LEAST);
			for (node *u = v; u != &root; u = get_last(u))
				if (u->leaf) {
					was = 1;
					break;
				}
			if (was) break;
		}
		if (was)
			printf("%s\n", t);
	}
	return 0;
}

