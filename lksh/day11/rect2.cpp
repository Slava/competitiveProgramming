#include <cstdio>
#include <cstdlib>
#define dbg(...) fprintf(stderr, __VA_ARGS__)
#define dbg(...) ;

const int N = 50100;
struct node {
	int x, y, size;
	node *l, *r;
	node(int _) {
		x = _; 
		y = rand(); 
		size = 1;
	}
};

int size(node *v) {
	return v ? v->size : 0;
}

void upd(node *v) {
	if (!v)return;
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
	else if (t->x > x)
		split(t->l, x, l, t->l), r = t;
	else split(t->r, x, t->r, r), l = t;
	upd(t);
}

void insert(node *&v, int x) {
	node *A, *B, *C, *n;
	n = new node(x);
	split(v, x - 1, A, B);
	split(B, x, B, C);
	merge(B, n, B);
	merge(A, B, v);
	merge(v, C, v);
}

void erase(node *&v, int x) {
	node *A, *B, *C;
	split(v, x - 1, A, B);
	split(B, x, B, C);
	if (B) merge(B->l, B->r, B);
	merge(A, B, v);
	merge(v, C, v);
}

node *t[N<<2]; 
int n, m, A[N], first, second, y1, y2;
void upd(int v, int x, bool first = 0) {
	if (!first)
	for (int i = v + n; i > 0; i /= 2)
		erase(t[i], A[v]);
	A[v] = x;
	for (int i = v + n; i > 0; i /= 2)
		insert(t[i], x);
}

void sum_treap(node *v) {
	int xm = (y2 - y1) / 2 + 1; xm = y2 - y1 - xm;
	node *A, *B, *C;
	split(v, y1 + xm, A, B);
	split(B, y2 - 1 - xm, B, C);
	second += size(C);
	first += size(A);
	merge(A, B, B); merge(B, C, v);
}

void get(int l, int r) {
	l += n; r += n;
	while (l <= r) {
		if (l & 1) sum_treap(t[l]);
		if (!(r&1))sum_treap(t[r]);
		l = (l + 1) / 2;
		r = (r - 1) / 2;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		upd(i, x, 1);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x1, x2, t;
		char cmd[3]; scanf("%s", cmd);
		if (cmd[0] == 'Q') {
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			x1--; x2--; first = second = 0;
			if (x1 > x2)
				t = x1, x1 = x2, x2 = t;
			if (y1 > y2)
				t = y1, y1 = y2, y2 = t;
			get(x1, x2);
			if (first > second)
				printf("1\n");
			else if (second > first)
				printf("2\n");
			else printf("0\n");
		}
		else {
			scanf("%d%d", &x1, &t);
			x1--; upd(x1, t);
		}
	}
	return 0;
}

