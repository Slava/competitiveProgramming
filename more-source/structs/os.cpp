#include <cstdio>
#include <cstdlib>
#define int long

struct item
{
	int x, y, se;
	item *l, *r, *pr;
	item (int _x, int _se, item *_pr)
	{
		l = r = 0;
		y = rand();
		x = _x;
		se = _se;
		pr = _pr;
	}
};

void merge (item *&t, item *l, item *r)
{
	if(!l || !r)
		t = l ? l : r;
	else if (l->y > r->y)
		merge(l->r, l->r, r), t = l;
	else merge(r->l, l, r->l), t = r;
}

void split (item *t, item *&l, item *&r, int x)
{
	if (!t)
		return void(l = r = 0);
	if (x >= t->x)
		split(t->r, t->r, r, x), l = t;
	else split(t->l, l, t->l, x), r = t;
}

void insert (item *&t, item *it)
{
	if (!t)
		t = it;
	else if (t->y < it->y)
		split(t, it->l, it->r, it->x), t = it;
	else insert(t->x > it->x ? t->l : t->r, it);
}

void remove (item *&t, int x, item *&W)
{
	if (!t)
		return;
	if (t == W)
		merge(t, t->l, t->r);
	else remove(t->x >= x ? t->l : t->r, x, W);
}

void go (item *&where, item *&what)
{
	if(!what)
		return;
	go(where, what->l);
	remove(where, what->se, what->pr);
	go(where, what->r);
}

item *beg, *end;

item * Right(item *t, int a, int b)
{
	if (!t)
		return 0;
	if (t->r)
		return Right(t->r,a,b);
	if (t->x <= a && t->pr->x >= b)
		return t;
	return 0;
}

void process(item *&aa, item *&bb, int a, int b)
{
	item *A, *B, *C;
	split(aa, B, C, b);
	split(B, A, B, a - 1);
	go(bb, B);
	merge(aa, A, C);
}

int gocount(item *t)
{
	if (!t)
		return 0;
	return 1 + gocount(t->l) + gocount(t->r);
}

main ()
{
	freopen ("os.in", "r", stdin);
//	freopen ("os.out", "w", stdout);
	FILE *out = fopen("os.out", "w");

	int m, n, a, b;
	item *T, *R, *A, *B, *C;
	scanf("%ld%ld", &m, &n);
	for (int i = 0; i < n; i++)
	{
		scanf ("%ld%ld", &a, &b);
		process(beg, end, a, b);
		process(end, beg, a, b);
		split(beg, B, C, b);
		T = Right(B, a, b);
		if(T)remove(end, T->pr->x, T->pr),
			remove(B, T->x, T);
		merge(beg, B, C);
		T = new item(a, b, 0);
		R = new item(b, a, T);
		T->pr = R;
		insert(beg, T);
		insert(end, R);
	}
	int res = gocount(beg);
	fprintf(out, "%ld\n", res);

	return 0;
}

