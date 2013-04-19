#include <cstdio>
#include <cstdlib>

struct node {
	int x, y, cnt;
	node *l, *r;
	node() {
		x = 0; 
		y = rand() | (rand() << 16);
		cnt = 1; l = r = 0;
	}
};

int cnt(node *v) {
	if (!v) return 0;
	return v->cnt;
}

void update(node *v) {
	if (!v) return;
	v->cnt = 1 + cnt(v->l) + cnt(v->r);
}

void split(node *t, int x, node *&l, node *&r) {
	if (!t)
		return void(l = r = 0);
	if (cnt(t->l) < x)
		split(t->r, x - cnt(t->l) - 1, t->r, r), l = t;
	else
		split(t->l, x, l, t->l), r = t;
	update(t);
}

void merge(node *l, node *r, node *&t) {
	if (!l || !r)
		t = l ? l : r;
	else if (l->y > r->y)
		merge(l->r, r, l->r), t = l;
	else merge(l, r->l, r->l), t = r;
	update(t);
}

int n, k, p, m;
int main() {
	node *t = 0, *v, *u;
	scanf("%d%d", &n, &k); p = k; m = n;
	for (int i = 1; i <= n; i++) {
		v = new node;
		v->x = i;
		merge(t, v, t);
	}
	for (int i = 0; i < m; i++) {
		split(t, p, t, u);
		split(t, p - 1, t, v);
		if (!v) throw;
		printf("%d ", v->x);
		merge(t, u, t); --n;
		if(i != m - 1)p = (p + k - 2) % n + 1;
	}
	return 0;
}
