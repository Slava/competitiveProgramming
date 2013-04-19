// 358
#include <cstdio>
#include <algorithm>

using namespace std;

int a[3][3], m[3];
int main ()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			scanf ("%d", &a[i][j]);
		sort(a[i], a[i] + 3);
		m[i] = a[i][1];
	}
	sort (m, m + 3);
	printf("%d", m[1]);
	return 0;
}

