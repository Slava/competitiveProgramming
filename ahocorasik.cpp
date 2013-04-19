#include <cstdio>
#include <cstring>

struct node{
	node *next[26], *go[26], *fail, *p, *last;
	int pch, leaf;
	node (){
		leaf = 0;
		last = p = fail = 0;
		memset(next, 0, sizeof next);
		memset(go, 0, sizeof go);
	}
}root, Nodes[40000];
int N, MM;
char s[1100][30];
int len[1100];

node *New(){
	return &Nodes[MM++];
}

void add_string (char *str, int sz){
	node *v = &root;
	for (; sz--; str++){
		int l = *str - 'a';
		if (!v->next[l]){
			v->next[l] = New();
			v->next[l]->p = v;
			v->next[l]->pch = l;
		}
		v = v->next[l];
	}
	v->leaf = ++N;
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

char t[10400];
int main (){
	int n; node *v = &root;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%s", s[i]);
		add_string(s[i], len[i] = strlen(s[i]));
	}
	scanf("%s", t);int sz = strlen(t);
	for (int i = 0; i < sz; i++){
		if (v->next[t[i] - 'a'])
			v = v->next[t[i] - 'a'];
		else v = go(v, t[i] - 'a');
		for (node *u = v; u != &root; u = get_last(u))
			if (u->leaf)
				printf("on %d found %s\n", 1 + i - len[u->leaf - 1], s[u->leaf - 1]);
	}
	return 0;
}

