#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>

struct item
{
	int y, cnt;
	char c;
	item *l, *r;
};

int sz(item *v)
{
	return v ? v->cnt : 0;
}

void upd(item *v)
{
	if (v)
		v->cnt = 1 + sz(v->l) + sz(v->r);
}

void merge (item *l, item *r, item *&t)
{
	if(!l || !r)
		t = l ? l : r;
	else if (l->y > r->y)
		merge(l->r, r, l->r), t = l;
	else merge(l, r->l, r->l), t = r;
	upd(t);
}

void split(item *t, int x, item *&l, item *&r)
{
	if (!t)
		return void(l = r = 0);
	if (sz(t->l) < x)
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

item * erase (item *&t, int i)
{
	item *l, *r;
	split(t, i, r, t);
	split(r, i - 1, l, r);
	merge(l, t, t);
	return r;
}

void insert (item *&t, int i, item *&l)
{
	item *r;
	split(t, i - 1, t, r);
	merge(t, l, t);
	merge(t, r, t);
}

item * find(item *&t, int i)
{
	item * r = erase(t, i);
	insert(t, i, r);
	return r;
}

item *t;
char s[20000000];
int main ()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int n, m, x, y;char cmd;
	scanf("%d%d%s", &n, &m, s);
	for (int i = 0; i < n; i++)
	{
		item *r = new item;
		r->y = rand();
		r->c = s[i];
		r->cnt = 1;
		merge(t, r, t);
	}
	for(int j = 0; j < m ; j++)
	{
		scanf("\n%c ", &cmd);
		if (cmd == 'q')
		{
			scanf ("%d", &x);
			printf("%c\n", find(t, x)->c);
		}
		else 
		{
			scanf("%d%d", &x, &y);
			item *l = erase(t, x);
			insert(t, y, l);
		}
	}
	
	FILE *rep = fopen("rep.txt", "w");
//	fprintf(rep, "%lf", double(clock()/(double(CLOCKS_PER_SEC))));
	std::cerr<<(double)time(0)/1000000000.0;

	return 0;
}


