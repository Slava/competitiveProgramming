#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cassert>

using namespace std;

struct node {
	int x, y, sum;
	node *l, *r;
} Nodes[101010];
int MM;

node *new_node(int _) {
	node *r = Nodes+MM++;
	r->y = rand();
	r->l = r->r = 0;
	r->sum = 1;
	r->x = _;
	return r;
}

int sum(node *v) {
	if (!v) return 0;
	return v->sum;
}

void upd(node *v) {
	if (!v) return;
	v->sum = 1 + sum(v->l) + sum(v->r);
}

void merge(node *l, node *r, node *&t) {
	if (!l || !r)
		t = l ? l : r;
	else if (l->y > r->y)
		merge(l->r, r, l->r), t = l;
	else merge(l, r->l, r->l), t = r;
	upd(l); upd(r);
}

void split(node *t, int x, node *&l, node *&r) {
	if (!t)
		l = r = 0;
	else if (t->x <= x)
		split(t->r, x, t->r, r), l = t;
	else split(t->l, x, l, t->l), r = t;
	upd(l); upd(r);
}

const int N = 101010;
node *v;
int n, q[N], M;
char s[N];

int whatIs(int x) {
	int l = 1, r = M, m;
	while(l<=r) {
		m = (l+r) / 2;
		node *A;
		split(v, m, A, v);
		int S = sum(A);
		merge(A,v,v);
		if (m-S >= x)
			r = m - 1;
		else l = m + 1;
	}
	return r + 1;
}

int main() {
	scanf("%d%d", &M, &n);
	for (int i = 0; i < n; i++)
		scanf("%s%d", s+i, q+i);
	for (int i = 0; i < n; i++)
		if (s[i] == 'L')
			printf("%d\n", whatIs(q[i]));
		else {
			int pos = whatIs(q[i]);
			node *A, *B;
			split(v, pos-1, A, v);
			split(v, pos, v, B);
			assert(!v);
			v = new_node(pos);
			merge(A,v,v);
			merge(v,B,v);
		}

	return 0;
}


