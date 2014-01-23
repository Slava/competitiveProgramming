#include <cstdio>
#include <ctime>
#include <cstdlib>
#define int long long
#define ll long long
struct item
{
	int x, y;
	ll sum;
	item *l, *r;
	item(int  _k)
	{
		x = _k;
		sum = x * 1ll;
		y = rand();
		l = r = 0;
	}
};

ll sum (item *t)
{
	if (!t)
		return 0;
	return t->sum*1ll;
}

void upd(item *t)
{
	if (!t)
		return;
	t->sum = sum(t->l) + sum(t->r) + t->x * 1LL;
}

void merge (item *&t, item *l, item *r)
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
	if (t->x <= x)
		split(t->r, t->r, r, x), l = t;
	else split(t->l, l, t->l, x), r = t;
	upd(t);
}

void insert (item *&t, item *it)
{
	if (!t)
		t = it;
	else if (it->y > t->y)
		split(t, it->l, it->r, it->x), t = it;
	else insert(it->x < t->x ? t->l : t->r, it);
	upd(t);
}

bool find(item *t, int key)
{
	while(t)
	{
		if (t->x == key)
			return 1;
		if (t->x < key)
			t = t->r;
		else t = t->l;
	}
	return 0;
}

item *t;
ll getsum(int x, int y)
{
	item *l, *r;
	split(t, l, t, y);
	split(l, l, r, x - 1);
	ll R = sum(r);
	merge(l, l, r);
	merge(t, l, t);
	return R;
}

main ()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	ll  sum, prev = 0, p = 1e9;
	int n, l, r, k;
	char cmd;
	scanf("%Ld\n", &n);
	for (int i = 0; i < n; i++)
	{
		scanf ("%c ", &cmd);
		if (cmd == '+')
		{
			scanf ("%Ld\n", &k);
			if(prev)
			{
				prev = prev % p;
				k = (prev + k * 1ll) % p;
			}
			if (!find(t, k))
			{
				item *l = new item(k);
				insert(t, l);
			}
			prev = 0;
		}
		else 
		{
			scanf("%Ld %Ld\n", &l, &r);
			prev = getsum(l,r);
			printf("%Ld\n", prev);
		}
	}

	FILE *rep = fopen("rep.txt", "w");
	fprintf(rep, "%.2lf", double(double(clock())/double(CLOCKS_PER_SEC)));

	return 0;
}


