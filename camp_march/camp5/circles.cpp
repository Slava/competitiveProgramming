#include <cstdio>
#include <ctime>

#define sqr(x) ((x)*(x))

const int N = 10100;
int n, x[N], y[N], r[N];

int ch;
void get(int &x)
{
	for (ch = getchar(); ch == ' ' || ch == '\n' || ch == '\r'; ch = getchar());
	for (; ch != ' ' && ch != '\n' && ch != '\r'; ch = getchar())
		x = x * 10 + ch - '0';
}

int main ()
{
	get (n);
	int i, j;
	for (i = 0; i < n; i++)
	{get(x[i]);get(y[i]);get(r[i]);}
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
			if (sqr(r[i] + r[j])  >= sqr(x[i] - x[j]) + sqr(y[i] - y[j]))
			{
				printf ("%d %d\n", i + 1, j + 1);
//				printf("timed: %lf\n", double(clock())/double(CLOCKS_PER_SEC));
				return 0;
			}
	puts("0");
//	printf("timed: %lf\n", double(clock())/double(CLOCKS_PER_SEC));
	return 0;
}

