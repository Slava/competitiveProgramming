#include <cstdio>
#include <cstdlib>

typedef long long Int;
struct node {
	node *L, *R;
	int l, r;
	Int sum;
	node(int tl, int tr) {
		L = R = 0; sum = 0;
		l = tl; r = tr;
	}
};
Int p = (Int)1e9, y, x, n;
char c[2];
node *v = new node(0, p);

Int sum(node *v) {
	return v ? v->sum : 0;
}

void upd(int x, node *&v, int l, int r) {
	if (!v) v = new node(l, r);
	if (l == r)
		v->sum = x;
	else {
		int m = (l + r) / 2;
		if (x > m)
			upd(x, v->R, m + 1, r);
		else upd(x, v->L, l, m);
		v->sum = sum(v->L) + sum(v->R);
	}
}

Int get(int l, int r, node *v) {
	if (!v || v->r < l || v->l > r)
		return 0;
	if (v->l >= l && v->r <= r)
		return v->sum;
	return get(l, r, v->L) + get(l, r, v->R);
}

int main() {
	scanf("%lld", &n);
	for (int i = 0; i < n; i++)	{
		scanf("%s", c);
		if (*c == '+') {
			scanf("%lld", &x);
			x = (x + y) % p; y = 0;
			upd(x, v, v->l, v->r);
		}
		else {
			scanf("%lld%lld", &x, &y);
			printf("%lld\n", y = get(x, y, v));
		}
	}
	return 0;
}
