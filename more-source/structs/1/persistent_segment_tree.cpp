// персистентное дерево отрезков на сумму
// работоспособность кода не проверял
// Славко 25.05.2011 1.13 AM
// С окончанием учебного года, блин!
#include <cstdio>
#define null NULL

struct node {
	int tl, tr, x;
	node *l, *r;
	node() { l = r = 0; tl = tr = x = 0; }
	node(node *l, node *r, int tl, int tr, int x) {
		this->l = l; this->r = r;
		this->tl = tl; this->tr = tr;
		this->x = x;
	}
};

void build(node *v, int tl, int tr) {
	v->tl = tl;
	v->tr = tr;
	if (tl != tr) {
		int m = (tl + tr) / 2;
		v->l = new node;
		v->r = new node;
		build(v->l, tl, m);
		build(v->r, m + 1, tr);
	}
}

node *add(node *v, int i, int x) {
	if (v->tl == v->tr)
		return new node(null, null, v->tl, v->tr, v->x + x);
	int m = (v->tl + v->tr) / 2;
	if (i <= m)
		return new node(add(v->l, i, x), v->r, v->tl, v->tr, v->x + x);
	else return new node(v->l, add(v->r, i, x), v->tl, v->tr, v->x + x);
}

int get(node *v, int l, int r) {
	if (v->tl == l && v->tr == r)
		return v->x;
	int m = (v->tl + v->tr) / 2;
	if (r <= m)
		return get(v->l, l, r);
	if (l > m)
		return get(v->r, l, r);
	return get(v->l, l, m) + get(v->r, m + 1, r);
}

int main() {
	return 0;
}

