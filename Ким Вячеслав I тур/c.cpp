// Kim Vyacheslav
// Karaganda KTL
// 15.03.2011
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

const int NN = 1000010;

struct tree
{
	int x, y;
	int n, m, mx;
	tree *l, *r;
	tree(int _x)
	{
		n = m = 1;
		mx = x = _x;
		y = rand();
		l = r = 0;
	}
};

void update (tree *v)
{
	if (!v)
		return ;
    if(v->n)v->m = v->n;
    else v->m = 0;
    v->mx = v->x;
	if (v->l)
        if (v->l->m > v->m || (v->l->m == v->m && v->l->mx < v->mx))
        {
            //printf("do update for %d and %d\n", v->x, v->l->x);
            v->m = v->l->m;
            v->mx = v->l->mx;
        }
	if (v->r)
        if (v->r->m > v->m || (v->r->m == v->m && v->r->mx < v->mx))
        {
            //printf("do update for %d and %d\n", v->x, v->r->x);
            v->m = v->r->m;
            v->mx = v->r->mx;
        }
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
	update(l); update(r);
}

tree *t;

void add(int x)
{
	tree *p = new tree(x), *l, *r;
	split (t, x, l, r);
	merge(l, p, l);
	merge(l, r, t);
}

void show (tree *t)
{
    if (!t)
        return ;
    show(t->l);
    printf("x=%d n=%d  m=%d mx=%d\n", t->x, t->n, t->m, t->mx);
    show(t->r);
}

bool find (tree *t, int X)
{
    if (!t)
        return 0;
    if (t->x == X)
    {
        t->n++;
        t->m = max(t->m, t->n);
        return 1;
    }
    if (t->x < X)
        if (find(t->r, X))
        {
            update(t);
            return 1;
        }
    if (t->x > X)
        if (find(t->l, X))
        {
            update(t);
            return 1;
        }
    return 0;
}

int main ()
{
	freopen ("C.in", "r", stdin);
	freopen ("C.out", "w", stdout);

	int n, m, x, y;
	char cmd[20];
	srand(123456789);
	scanf ("%d\n", &n);
	for (int i = 0; i < n; i++)
	{
//	    cin >> cmd >> x;
	    scanf("%s %d\n", cmd, &x);
	    if (cmd[0] == '+')
        {
            tree *A, *B, *C, *D;
            split(t, x, B, C);
            split(B, x - 1, A, B);
            if (!B)
                B = new tree(x);
            else B->n++, update(B);

            merge(A, B, t);
            merge(t, C, t);
            update(t);
        }
        if (cmd[0] == '-')
        {
            tree *A, *B, *C, *D;
            split(t, x, B, C);
            split(B, x - 1, A, B);
            B->n--;
            merge(A, B, t);
            merge(t, C, t);
            update(t);
        }
        if (t)
            if(t->m)
                printf("%d\n", t->mx);
            else printf("0\n");
        else printf("0\n");
       // show (t);
	}
	fprintf(stderr, "%.4lf", double(clock())/double(CLOCKS_PER_SEC));
	return 0;
}


