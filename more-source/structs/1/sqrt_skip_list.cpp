#include <cstdio>

using namespace std;

const int N = 10000000;
const int SQRTN = 1500;
struct item
{
	char v;
	item *nxt, *prv;
	item(char _v, item *l = 0, item *r = 0)
	{
		v = _v;
		prv = l;
		nxt = r;
	}
	item(){nxt=prv=0;}
}head, tail, *bl[SQRTN];
item * find(int k)
{
	int b, p, i;
	b = k / SQRTN;
	p = k % SQRTN;
	item *c;
	c = bl[b];
	for (i = 0; i < p; i++)
		c = c->nxt;
	return c;
}
void ins (int k, item *obj)
{
	int b, p, i;
	b = k / SQRTN;
	p = k % SQRTN;
	item *c;
	c = find(k - 1);
	obj->nxt = c->nxt;
	c->nxt = obj;
	obj->prv = c;
	obj->nxt->prv = obj;
	i = p ? b + 1 : b;
	for (; bl[i]; i++)
		bl[i] = bl[i]->prv;
}
item * del (int k)
{
	int i, b, p;
	b = k / SQRTN;
	p = k % SQRTN;
	item *c;
	c = find(k);
	c->nxt->prv = c->prv;
	c->prv->nxt = c->nxt;
	i = p ? b + 1 : b;
	for (; bl[i]; i++)
		bl[i] = bl[i]->nxt;
	return c;
}
int main ()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	int n, m, l, r;
	char cmd, s[N];
	item *cur, *temp;
	bl[0] = cur = &head;
	scanf ("%d%d%s", &n, &m, s);
	for (int i = 0; i < n;)
	{
		cmd = s[i];
		temp = new item(cmd, cur);
		cur->nxt = temp;
		cur = temp;++i;
		if (i % SQRTN == 0)
			bl[i / SQRTN] = temp;
	}
	cur->nxt = &tail;
	while (m--)
	{
		scanf ("%c", &cmd);
		if (cmd == 'a')
		{
			scanf ("%d%d", &l, &r);
			temp = del(l);
			ins(r, temp);
		}
		else {
			scanf ("%d", &l);
			temp = find(l);
			printf("%c\n", temp->v);
		}
	}
	
	return 0;
}

