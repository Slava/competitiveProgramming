#include <cstdio>


int mem[200], n, m, t, T = 1;
char cmd[20];

void ers (int y)
{
	bool was = 0;
	for (int i = 1; i <= m; i++)
		if (mem[i] == y)
			mem[i] = 0, was = 1;
	if (!y)
		was = 0;
	if (!was)
		puts("ILLEGAL_ERASE_ARGUMENT");
}

void alc (int x)
{
	for (int i = 1; i <= m; i++)
		if (!mem[i])
		{
			bool can = 1;
			if (i + x - 1 <= m)
			{
				for (int j = 0; j < x; j++)
					if (mem[i + j])
						can = 0;
			}
			else can = 0;
			if (can)
			{
				for (int j = 0; j < x; j++)
					mem[i + j] = T;
				printf("%d\n", T++);
				return;
			}
		}
	puts("NULL");
}

void dfg ()
{
	int t = 1;
	while (mem[t]) 
		t++;
	for (int i = t; i <= m; i++)
		if (mem[i])
			mem[t++] = mem[i],
			mem[i] = 0;
}

int main ()
{
	scanf ("%d%d", &n, &m);
	while (n--)
	{
		scanf ("%s", cmd);
		if (cmd[0] != 'd')
			scanf ("%d", &t);
		if (cmd[0] == 'd')
			dfg();
		else if (cmd[0] == 'e')
			ers(t);
		else alc(t);
	}
	return 0;
}

