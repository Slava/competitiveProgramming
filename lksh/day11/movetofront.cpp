#include <cstdio>
#include <cstdlib>

struct node {
	node *l, *r;
	int x, y, size;
	node(int _) {
		x = _;
		l = r = 0;
		y = rand();
		size = 1;
	}
};

int size(node *v) {
	return v ? v->size : 0;
}

void upd(node *v) {
	if (!v) return;
	v->size = 1 + size(v->l) + size(v->r);
}

void merge(node *l, node *r, node *&t) {
	if (!l || !r)
		t = l ? l : r;
	else if (l->y > r->y)
		merge(l->r, r, l->r), t = l;
	else merge(l, r->l, r->l), t = r;
	upd(t);
}

void split(node *t, int x, node *&l, node *&r) {
	if (!t)
		l = r = 0;
	else if (size(t->l) >= x)
		split(t->l, x, l, t->l), r = t;
	else split(t->r, x - size(t->l) - 1, t->r, r), l = t;
	upd(t);
}

void show(node *v) {
	if (!v)return;
	show(v->l);
	printf("%d ", v->x);
	show(v->r);
}

node *t, *A, *B, *C;
int n, m, l, r;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		A = new node(i);
		merge(t, A, t);
	}
	for (; m--; ) {
		scanf("%d%d", &l, &r);
		split(t, r, B, C);
		split(B, l - 1, A, B);
		merge(B, A, A);
		merge(A, C, t);
	}
	show(t);
	return 0;
}

