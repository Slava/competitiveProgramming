#include <cstdio>
#include <ctime>
#include <cstdlib>

struct item
{
	int y, i, cnt;
	item *l, *r;
	item(int _i)
	{
		l = r = 0;
		cnt = 1;
		y = rand();
		i = _i;
	}
};

int cnt(item *v)
{
	return v ? v->cnt : 0;
}

void upd(item *v)
{
	if(!v)
		return ;
	v->cnt = 1 + cnt(v->l) + cnt(v->r);
}

void merge(item *&t, item *l, item *r)
{
	if (!l || !r)
		t = l ? l : r;
	else if (l->y > r->y)
		merge(l->r, l->r, r), t = l;
	else merge(r->l, l, r->l), t = r;
	upd(t);
}

void split(item *t, item *&l, item *&r, int x)
{
	if (!t)
		return void(l = r = 0);
	if (cnt(t->l) < x)
		split(t->r, t->r, r, x - cnt(t->l) - 1), l = t;
	else split(t->l, l, t->l, x), r = t;
	upd(t);
}

void show(item *t)
{
	if(!t)
		return ;
	show(t->l);
	printf("%d ", t->i);
	show(t->r);
}

item *t, *r, *l;
int n, m, x, y;

int main ()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n ; i++)
	{
		r = new item(i);
		merge(t, t, r);
	}
	
	for (int i = 0; i < m; i++)
	{
		scanf ("%d%d", &x, &y);
		split(t, l, t, y);
		split(l, l, r, x - 1);
		merge(l, r, l);
		merge(t, l, t);
	}
	
	show(t);
	FILE *rep = fopen("rep.txt", "w");
	fprintf(rep, "%lf", double(clock()/(double)(CLOCKS_PER_SEC)));

	return 0;
}

