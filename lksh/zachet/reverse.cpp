#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct node {
	node *l, *r;
	int x, y, size, rev;
	node(int _) {
		x = _;
		l = r = 0;
		y = rand();
		size = 1;
		rev = 0;
	}
};

int size(node *v) {
	return v ? v->size : 0;
}

void push(node *v) {
	if (!v || !v->rev) return;
	swap(v->l, v->r);
	if (v->l) v->l->rev ^= 1;
	if (v->r) v->r->rev ^= 1;
	v->rev = 0;
}

void upd(node *v) {
	if (!v) return;
	v->size = 1 + size(v->l) + size(v->r);
}

void merge(node *l, node *r, node *&t) {
	push(l); push(r);
	if (!l || !r)
		t = l ? l : r;
	else if (l->y > r->y)
		merge(l->r, r, l->r), t = l;
	else merge(l, r->l, r->l), t = r;
	upd(t);
}

void split(node *t, int x, node *&l, node *&r) {
	push(t);
	if (!t)
		l = r = 0;
	else if (size(t->l) >= x)
		split(t->l, x, l, t->l), r = t;
	else split(t->r, x - size(t->l) - 1, t->r, r), l = t;
	upd(l); upd(r);
}

void show(node *v) {
	if (!v)return;
	push(v);
	show(v->l);
	printf("%d ", v->x);
	show(v->r);
}

node *t, *A, *B, *C;
int n, m, l, r, x;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		A = new node(x);
		merge(t, A, t);
	}
//	show(t);
	for (; m--; ) {
		scanf("%d%d%d", &x, &l, &r);
		split(t, r, B, C);
		split(B, l - 1, A, B);
		if (x == 2) {
			merge(B, A, A);
			merge(A, C, t);
		}
		else {
			B->rev ^= 1;
			merge(A, B, t);
			merge(t, C, t);
		}
//		show(t);printf("\n");
	}
	show(t);
	return 0;
}

