#include <cstdio>
#include <cstdlib>

struct node {
	node *l, *r;
	long long sum, x, y;
	node(long long _) {
		x = _;
		l = r = 0;
		y = rand();
		sum = x;
	}
};

void upd(node *v) {
	if (!v) return;
	v->sum = v->x;
	if (v->l) v->sum += v->l->sum;
	if (v->r) v->sum += v->r->sum;
}

void merge(node *l, node *r, node *&t) {
	if (!l || !r)
		t = l ? l : r;
	else if (l->y > r->y)
		merge(l->r, r, l->r), t = l;
	else merge(l, r->l, r->l), t = r;
	upd(t);
}

void split(node *t, long long x, node *&l, node *&r) {
	if (!t)
		l = r = 0;
	else if (t->x > x)
		split(t->l, x, l, t->l), r = t;
	else split(t->r, x, t->r, r), l = t;
	upd(t);
}

char s[9];
node *t, *A, *B, *C;
long long k, l, r, sum;
int main() {
	scanf("%Ld", &k);
	for (;k--;) {
		scanf("%s", s);
		if (s[0] == '+') {
			scanf("%Ld", &l);
			l = (l + sum) % 1000000000;
			sum = 0;
			split(t, l - 1, A, t);
			split(t, l, t, B);
			if (!t) t = new node(l);
			merge(A, t, t);
			merge(t, B, t);
		}
		else {
			scanf("%Ld%Ld", &l, &r);
			split(t, r, B, C);
			split(B, l - 1, A, B);
			if (!B) sum = 0;
			else sum = B->sum;
			printf("%Ld\n", sum);
			merge(A, B, t);
			merge(t, C, t);
		}
	}
	return 0;
}

