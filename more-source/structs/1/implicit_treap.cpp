#include <cstdio>
#include <cstdlib>

struct item {
	int y, cnt;
	char c;
	item *l, *r;
};

int sz(item *v) {
	return v ? v->cnt : 0;
}

void upd(item *v) {
	if (v) v->cnt = 1 + sz(v->l) + sz(v->r);
}

void merge (item *l, item *r, item *&t) {
	if(!l || !r)
		t = l ? l : r;
	else if (l->y > r->y)
		merge(l->r, r, l->r), t = l;
	else merge(l, r->l, r->l), t = r;
	upd(t);
}

void split(item *t, int x, item *&l, item *&r) {
	if (!t)
		l = r = 0;
	else if (sz(t->l) < x)
		split(t->r, x - sz(t->l) - 1, t->r, r), l = t;
	else split(t->l, x, l, t->l), r = t;
	upd(t);
}

void show (item *v)
{
	if (!v)
		return ;
	show(v->l);
	putchar(v->c);
	show(v->r);
}

void erase (item *&t, int i)
{
	item *l, *r;
	split(t, i, r, t);
	split(r, i - 1, l, r);
	merge(l, t, t);
}

void insert (item *&t, int i, char _c)
{
	item *l, *r;
	l = new item;
	l->c = _c;
	l->y = rand();
	l->cnt = 1;
	split(t, i - 1, t, r);
	merge(t, l, t);
	merge(t, r, t);
}

item *t;
int main ()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int n;char s[200];
	scanf("%d%s", &n, s);
	for (int i = 0; i < n; i++)
	{
		item *r = new item;
		r->y = rand();
		r->c = s[i];
		r->cnt = 1;
		merge(t, r, t);
	}
	item *ans, *tans;
	erase(t, 1);
	insert(t,2,'X');
	show(t);

	return 0;
}


