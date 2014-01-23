#include <cstdio>
#include <ctime>

const int NN = 50010;
struct item
{
	int x, y, l, r;
	item()
	{
		l = r = 0;
	}
}T[NN];
int N = 2,
	p[NN];
void merge (int &t, int l, int r)
{
	if (!l || !r)
		t = l ? l : r;
	else if (T[l].y > T[r].y)
		merge(T[l].r, T[l].r, r), t = l;
	else merge(T[r].l, l, T[r].l), t = r;
}

void split (int t, int &l, int &r, int x)
{
	if (!t)
		return void(l = r = 0);
	if (T[t].x < x)
		split(T[t].r, T[t].r, r, x), l = t;
	else split(T[t].l, l, T[t].l, x), r = t;
}

void insert(int &t, int el)
{	
	if (!t)
		t = el;
	else if (T[el].y > T[t].y)
		split(t, T[el].l, T[el].r, T[el].x), t = el;
	else insert(T[el].x < T[t].x ? T[t].l : T[t].r, el);
}

void solve (int t)
{
	if (!t)
		return;
	p[T[t].l] = p[T[t].r]  = t;
	solve(T[t].l);
	solve(T[t].r);
}

int main ()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, root = 1;
	scanf ("%d%d%d", &n, &T[1].x, &T[1].y);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &T[N].x, &T[N].y);
		insert(root, N); N++;
	}
	puts("YES");
	solve(root);
	for (int i = 1; i <= n; i++)
		printf("%d %d %d\n", p[i], T[i].l, T[i].r);
	
	FILE *rep = fopen("rep.txt", "w");
	fprintf(rep, "%lf", double(clock()/(double)CLOCKS_PER_SEC));

	return 0;
}

