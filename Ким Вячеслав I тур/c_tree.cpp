#include <cstdio>
#include <algorithm>
#include <ctime>

using namespace std;

const int N = 200000;
int t[2*N], p[2*N], a[N], b[N], c[N], ln;

void add (int pos, int x, int i = 1, int tl = 0, int tr = ln - 1)
{
	if (tl == tr)
		t[i] = x, p[i] = pos;
	else
	{
		int m = (tl + tr) >> 1;
		if (pos <= m)
			add(pos, x, i + i, tl ,m);
		else add(pos, x, i + i + 1, m + 1, tr);
		if (t[i + i + 1] > t[i + i])
			t[i] = t[i + i + 1], p[i] = p[i + i + 1];
		else t[i] = t[i + i], p[i] = p[i + i];
	}
}

void init()
{
	FILE *in = fopen("C.in", "r");
	int n, x; char C;
	fscanf(in, "%d\n", &n);
	for (int i = 0; i < n; i++)
		fscanf (in, "%c %d\n", &C, &b[i]);
	sort(b, b + n);
	for (int i = 0; i < n; i++)
		if (!i || b[i] != b[i - 1])
			c[ln++] = b[i];
	fclose(in);
}

int main ()
{
	init();
	FILE *in = fopen("C.in", "r"),
		*out = fopen("C.out", "w");
	
	int n, x;char cmd;
	fscanf (in, "%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		fscanf (in, "%c %d\n", &cmd, &x);
		int pos = lower_bound (c, c + ln, x) - c;
		if (cmd == '+')
			a[pos]++;
		else a[pos]--;
		add(pos, a[pos]);
		fprintf(out, "%d\n", c[p[1]]);
	}
	fprintf(stderr, "%.4lf", double(clock())/double(CLOCKS_PER_SEC));
	return 0;
}

