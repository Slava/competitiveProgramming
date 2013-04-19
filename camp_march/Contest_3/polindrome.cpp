#include <cstdio>
#include <cstring>

#ifdef WIN32
	#define i64 "%I64d"
#else 
	#define i64 "%lld"
#endif

struct node
{
	int x; node *nxt, *prv;
	node (){nxt = prv = 0; x = 0;}
}Nodes[1010101];
int nn;

node * New () { return &Nodes[nn++]; }

struct mylist
{
	node *b, *e;
	int size;
	mylist () {b = e = 0; size = 0;}
	void push (int x)
	{
		node *l = New();
		l->x = x;
		if (!b)
			b = e = l;
		else 
		{
			e->nxt = l;
			l->prv = e;
			e = l;
		}
		size++;
	}
	int front () { return b->x; }
	int back () { return e->x; }
	void pop_back () { e = e->prv;size--; }
	void pop_front () { b = b->nxt;size--; }
};

const int N = 1010101;
mylist l[26];
char s[N];
int n, t[N * 2], noans, u[N];
long long ans;

void build (int i = 1, int l = 0, int r = n - 1)
{
	if (l == r)
		t[i] = l;
	else build(i + i, l, (l + r) / 2), build(i + i + 1, (l + r) / 2 + 1, r);
}

void upd (int l, int r, int x, int i = 1, int tl = 0, int tr = n - 1)
{
	if (l == tl && r == tr)
		t[i] += x;
	else
	{
		int tm = (tl + tr) / 2;
		t[i + i] += t[i];
		t[i + i + 1] += t[i];
		t[i] = 0;
		if (l > tm)
			upd (l, r, x, i + i + 1, tm + 1, tr);
		else if (r <= tm)
			upd (l, r, x, i + i, tl, tm);
		else{upd (l, tm, x, i + i, tl, tm); upd(tm + 1, r, x, i + i + 1, tm + 1, tr);}
	}	
}

int get (int p, int i = 1, int tl = 0, int tr = n - 1)
{
	if (tl == tr)
		return t[i];
	int tm = (tl + tr) / 2;
	if (p > tm)
		return t[i] + get(p, i + i + 1, tm + 1, tr);
	return t[i] + get(p, i + i, tl, tm);
}

main ()
{
	scanf ("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; i++)
		l[s[i] - 'A'].push(i);
	for (int i = 0; i < 26; i++)
		if (l[i].size % 2)
			noans++;
	if (noans > 1)
	{
		puts("-1");
		return 0;
	}
	build();

	int q, p, L, R, chose, P, Q, oL, oR;
	Q = 0; P = n - 1;
	
	for (; Q < P; )
	{
		p = get(P);
		q = get(Q);
		oL = l[s[P] - 'A'].front();
		oR = l[s[Q] - 'A'].back();
		L = get(oL);
		R = get(oR);
		if ((l[s[Q] - 'A'].size == 1 || L - q < p - R) && l[s[P] - 'A'].size != 1)
		{
			chose = s[P] - 'A';
			upd(0, oL, 1);
			ans += L - q;
		}
		else
		{
			chose = s[Q] - 'A';
			ans += p - R;
			upd(oR, n - 1, -1);
		}
		u[l[chose].front()] = u[l[chose].back()] = 1;
		l[chose].pop_front(); l[chose].pop_back();
		while (u[Q])Q++;
		while (u[P])P--;
	}
	printf(i64 "\n", ans);

	return 0;
}

