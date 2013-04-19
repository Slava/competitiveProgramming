#include <cstdio>
#include <algorithm>

using namespace std;

bool inrec (int x, int y, int x1, int y1, int x2, int y2)
{
	return (x > x1 && x < x2 && y > y1 && y < y2);
}

bool inter (int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	if (y1 > y2)swap(y1,y2);
	if (y3 > y4)swap(y3,y4);
	if (x1 > x2)swap(x1,x2);
	if (x3 > x4)swap(x3,x4);
	if (y1 == y2 && y2 == y3 && y3 == y4)
		return (x3 >= x1 && x2 >= x4) || (x3 > x1 && x4 > x2 && x3 < x2) ||
				(x1 >= x3 && x4 >=x2) || (x1 > x3 && x2 > x4 && x1 < x4);
	else if(x1 == x2 && x2 == x3 && x3 == x4)
		return (y3 >= y1 && y2 >= y4) || (y3 > y1 && y4 > y2 && y3 < y2) ||
				(y1 >= y3 && y4 >=y2) || (y1 > y3 && y2 > y4 && y1 < y4);
	return 0;
}

void solve ()
{
	int x1[2], y1[2], x2[2], y2[2];
	scanf ("%d%d%d%d%d%d%d%d", 
	&x1[0], &y1[0], &x1[1], &y1[1], 
	&x2[0], &y2[0], &x2[1], &y2[1]);
	if (x1[0] > x1[1])
		swap(x1[0], x1[1]);
	if (x2[0] > x2[1])
		swap(x2[0], x2[1]);
	if (y1[0] > y1[1])
		swap(y1[0], y1[1]);
	if (y2[0] > y2[1])
		swap(y2[0], y2[1]);
	for (int i = x1[0] + 1; i < x1[1]; i++)
		if (inrec(i, y1[0], x2[0], y2[0], x2[1], y2[1]) || inrec(i, y1[1], x2[0], y2[0], x2[1], y2[1]))
		{
			printf("3");
			return;
		}
	for (int i = y1[0] + 1; i < y1[1]; i++)
		if (inrec(x1[0], i, x2[0], y2[0], x2[1], y2[1]) || inrec(x1[1], i, x2[0], y2[0], x2[1], y2[1]))
		{
			printf("3");
			return;
		}	

	for (int i = x2[0] + 1; i < x2[1]; i++)
		if (inrec(i, y2[0], x1[0], y1[0], x1[1], y1[1]) || inrec(i, y2[1], x1[0], y1[0], x1[1], y1[1]))
		{
			printf("3");
			return;
		}
	for (int i = y2[0] + 1; i < y2[1]; i++)
		if (inrec(x2[0], i, x1[0], y1[0], x1[1], y1[1]) || inrec(x2[1], i, x1[0], y1[0], x1[1], y1[1]))
		{
			printf("3");
			return;
		}	
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			if (inter(x1[0],y1[i],x1[1],y1[i], x2[0],y2[j],x2[1],y2[j]) || 
				inter(x1[i],y1[0],x1[i],y1[1], x2[j],y2[0],x2[j],y2[1]))
				{
					printf("2");
					return;
				}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				for (int l = 0; l < 2; l++)
					if (x1[i] == x2[j] && y1[k] == y2[l])
					{
						printf("1");
						return;
					}
	printf("0");
}

int main ()
{
	freopen ("area.in", "r", stdin);
	freopen ("area.out", "w", stdout);
	int t;
	scanf ("%d", &t);
	while (t--)
		solve();
	return 0;
}


