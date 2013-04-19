#include <cstdio>
#include <cstdlib>

struct node
{
	int x, y;
	node () {x = 0; y = rand();}
};

void split (node *t, int x, node *&l, node *&r)
{
	if (!t)
		l = r = 0;
	else if (t->x <= x)
		split (t->r, x, t->r, r), l = t;
	else split (t->l, x, l, t->l), r = t;
}

void merge (node *l, node *r, node *&t)
{
	if  (!l || !r)
		t = l ? l : r;
	else if (l->y <= r->y)
		merge(l, r->l, r->l), t = r;
	else merge(l->r, r, l->r), t = l;
}

node weWillNeverDie[101010];
int mm;
node *New (int _x)
{
	weWillNeverDie[mm].x = _x;
	return *weWillNeverDie[mm++];
}



