#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct node {
	node *l, *r;
	bool eqf;
	int y, size;
	long long sum, pl, eq, mg, x;
	node() {
		sum = x = 0;
		l = r = 0;
		size = 1;
		pl = eq = mg = eqf = 0;
	}
}have[200010];
int mm, arr[200010];

void init() {
	for (int i = 0; i < 200010; i++)
		arr[i] = i;
	random_shuffle(arr, arr + 200010);
	for (int i = 0; i < 200010; i++)
		have[i].y = arr[i];
}

node *new_node(int v) {
	node *r = &have[mm++];
	r->x = r->sum = v;
	return r;
}

inline int size(node *v) {
	return v ? v->size : 0;
}

inline long long sum(node *v) {
	return v ? v->sum : 0;
}

inline void upd(node *v) {
	if (!v) return;
	v->size = 1 + size(v->l) + size(v->r);
	if (v->eqf) v->sum = size(v) * v->eq;
	else 
		v->sum = sum(v->l) + sum(v->r) + v->x;
	v->sum += v->pl * size(v) + 
		v->mg * (size(v) * 1LL * (size(v) + 1LL) / 2LL);
}

inline void push(node *v) {
	if (!v) return;
	if (v->eqf) {
		v->x = v->eq;
		if (v->l) 
			v->l->eqf = 1,
			v->l->eq = v->eq,
			v->l->pl = v->l->mg = 0;
		if (v->r) 
			v->r->eqf = 1,
			v->r->eq = v->eq,
			v->r->pl = v->r->mg = 0;
	}
	if (v->pl) {
		v->x += v->pl;
		if (v->l)
			v->l->pl += v->pl;
		if (v->r)
			v->r->pl += v->pl;
	}
	if (v->mg) {
		if (v->l)
			v->l->mg += v->mg;
		int k = size(v->l) + 1;
		v->x += k * v->mg;
		if (v->r) {
			v->r->pl += k * v->mg;
			v->r->mg += v->mg;
		}
	}
	v->eqf = v->mg = v->pl = 0;
	upd(v->l); upd(v->r); upd(v);
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
//	upd(l); upd(r);
	upd(t);
}

node *t, *A, *B, *C;
int n, m, l, r, x, cmd;
int main() {
	init();
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		A = new_node(x);
		merge(t, A, t);
	}
	for (int k = 0; k < m; k++) {
		scanf("%d%d%d", &cmd, &l, &r);
		if (cmd == 3) {
			split(t, l - 1, A, B);
			C = new_node(r);
			merge(A, C, A);
			merge(A, B, t);
			goto end;
		}
		split(t, r, B, C);
		split(B, l - 1, A, B);
		upd(A); upd(B); upd(C);
		if (cmd == 1) {
			scanf("%d", &x);
			push(B);
			if (B) {
				B->eqf = 1; 
				B->eq = x; 
				B->mg = B->pl = 0;
				upd(B);
			}
		}
		else if (cmd == 2) {
			scanf("%d", &x);
			push(B);
			if (B) {
				B->mg = x;
				upd(B);
			}
		}
		else if (cmd == 4)
			printf("%lld\n", sum(B));
		merge(A, B, t);
		merge(t, C, t);
		end:;
	}
	return 0;
}

