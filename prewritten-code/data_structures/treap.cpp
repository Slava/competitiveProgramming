#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

#define forn(i,n) for(int i = 0; i < n; i++)

const int NN = 1000010;

struct tree
{
	int x, y, sz;
	char c;
	tree *l, *r;
	tree(int _x, char _c)
	{
		c = _c;
		x = _x;
		y = rand();
		l = r = 0;
	}
};

void update (tree *v)
{
	if (!v)
		return ;
	v->sz = 1;
	if (v->l)
		v->sz += v->l->sz;
	if (v->r)
		v->sz += v->r->sz;
}

void merge (tree *l, tree *r, tree *&t)
{
	if (!l || !r)
		t = l ? l : r;
	else if (l->y > r->y)
		merge(l->r, r, l->r), t = l;
	else 
		merge(l, r->l, r->l), t = r;
	update(t);
}

void split (tree *t, int x, tree *&l, tree *&r)
{
	if (!t)
		l = r = 0;
	else if (x < t->x)
		split(t->l, x, l, t->l), r = t;
	else split(t->r, x, t->r, r), l = t;
	update(t);
}

tree *t;

void show (tree *t)
{
	if (!t)
		return;
	show(t->l);
	putchar(t->c);
	show(t->r);
}

void add(int x, char c)
{
	tree *p = new tree(x, c);
	merge(t, p, t);
}

int main ()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	
	int n, m, x, y;
	char s[NN], cmd;
	srand(123456789);
	scanf ("%d%s", &n, s);
	forn(i, n)
		add (i + 1, s[i]);
	show(t);
	return 0;
}

