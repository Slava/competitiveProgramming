#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, a[500][500];
int main ()
{
	FILE *in = fopen("windows.in", "r");

	fscanf (in, "%d", &N);
	int x1, y1, x2, y2;
	for (int i = 0; i < N; i++)
	{
		fscanf (in, "%d%d%d%d", &x1, &y1, &x2, &y2);
		x1 += 100; x2 += 100; y1 += 100; y2 += 100;
        for (int x = x1; x <= x2; x++)
            for (int y = y1; y <= y2; y++)
                a[x][y]++;
	}
	scanf("%d %d", &x1, &y1);
	printf("%d\n", a[x1 + 100][y1 + 100]);
	return 0;
}
