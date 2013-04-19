#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

//typedef unsigned long long ull;
typedef unsigned int ull;
const int M = 210;
const int NN = 1010;
ull p[M], P = 1717, pr[NN][M];
char s[NN][M];
int n, N = 105, ans[NN], ansl[NN], size[NN], maxlen;
int used[1000010], un;
struct node
{
	ull x;
	int n, ne;
	node()	{ x = 0; ne = n = 0;}
}Nodes[5001000];
bool check(ull, int);
int mm = 1;
int New(ull _)
{
	Nodes[mm].x = _;
	Nodes[mm].ne = 0;
	Nodes[mm].n = 1;
	return mm++;
}
int e[1000010];
ull ts =1000007;
void add(ull x)
{
	if (check(x, 1))
		return;
	ull p = x % ts;
	int o = New(x);
	if (!e[p])
	{
		e[p] = o;
		used[un++] = p;
	}
	else
	{
		Nodes[o].ne = e[p];
		e[p] = o;
	}
}
void del (ull x)	{	check(x, 2);	}
bool check(ull x, int inv = 0)
{
	ull p = x % ts;
	int u = e[p];
	for (; u; u = Nodes[u].ne)
		if (Nodes[u].x == x)
		{
			if (inv == 1)
				Nodes[u].n++;
			if (inv == 2 && Nodes[u].n > 0)
				Nodes[u].n--;
			if (Nodes[u].n > 0)
				return 1;
		}
	return 0;
}

inline ull hash(int i, int l, int r)
{
	ull h = pr[i][r];
	if (l) h -= pr[i][l - 1];
	h *= p[N - l - 1];
	return h;
}


int main ()
{
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%s", s[i]);
	p[N - 1] = 1;
	for (int i = N - 2; i >= 0; i--)
		p[i] = p[i + 1] * P;
	for (int i = 0; i < n; i++)
	{
		int sz = size[i] = strlen(s[i]);
		maxlen = max(sz, maxlen);
		for (int j = 0; j < sz; j++)
		{
			pr[i][j] = (s[i][j] - 'a' + 1) * p[j];
			if (j) pr[i][j] += pr[i][j - 1];
		}
	}
	for (int i = 1; i <= maxlen; i++)
	{
		for (int j = 0; j < n; j++)
			for (int k = 0; k + i <= size[j]; k++)
				add(hash(j, k, k + i - 1));
		for (int j = 0; j < n; j++)	if (!ansl[j])
		{
			for (int k = 0; k + i <= size[j]; k++)
				del(hash(j, k, k + i - 1));
			for (int k = 0; k + i <= size[j]; k++)
				if (!check(hash(j, k, k + i - 1)))
				{
					ans[j] = k; ansl[j] = i;
					break;
				}
			for (int k = 0; k + i <= size[j]; k++)
				add(hash(j, k, k + i - 1));
		}
//		memset(e, 0, sizeof e);
		for (int j = 0; j < un; j++)
			e[used[j]] = 0;
		un = 0;	mm = 1;
	}
	for (int i = 0; i < n; i++){
		for (int j = ans[i]; j < ans[i] + ansl[i]; j++)
			printf("%c", s[i][j]);
		puts("");
	}
	return 0;
}

