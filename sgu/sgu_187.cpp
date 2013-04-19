#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std; 

struct item {
	int y, cnt, x;
	bool flag;
	item *l, *r;
} Nodes[130010];
int Used;

item *newItem(int x) {
	item *r = Nodes+Used++;
	r->x = x;
	r->l = r->r = 0;
	r->flag = 0;
	r->y = rand();
	return r;
}

int sz(item *v) {
	return v ? v->cnt : 0;
}

void upd(item *v) {
	if (v) v->cnt = 1 + sz(v->l) + sz(v->r);
}

void push(item *v) {
	if (!v)return;
	if (v->flag) {
		if (v->l)
			v->l->flag ^= 1;
		if (v->r)
			v->r->flag ^= 1;
		v->flag = 0;
		swap(v->l, v->r);
	}
}

void merge (item *l, item *r, item *&t) {
	push(l); push(r);
	if(!l || !r)
		t = l ? l : r;
	else if (l->y > r->y)
		merge(l->r, r, l->r), t = l;
	else merge(l, r->l, r->l), t = r;
	upd(l); upd(r);
}

void split(item *t, int x, item *&l, item *&r) {
	push(t);
	if (!t)
		l = r = 0;
	else if (sz(t->l) < x)
		split(t->r, x - sz(t->l) - 1, t->r, r), l = t;
	else split(t->l, x, l, t->l), r = t;
	upd(l); upd(r);
}

void show (item *v) {
	if (!v)
		return ;
	push(v);
	show(v->l);
	printf("%d ", v->x);
	show(v->r);
}

item *v, *A, *B, *C;
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		A = newItem(i+1);
		merge(v,A,v);
	}

	while (m--) {
		int l, r;
		scanf("%d%d", &l, &r);
		split(v, r, B, C);
		split(B, l-1, A, B);
		B->flag ^= 1;
		merge(A, B, v);
		merge(v, C, v);
	}

	show(v);

	return 0;
}
