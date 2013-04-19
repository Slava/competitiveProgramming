#include <cstdio>
#include <cstdlib>

int s, res, a[10][100];
int main (){
	scanf("%d", &s); a[0][0] = 1;
	for (int i = 0; i < 10; i++)
		a[1][i] = 1;
	for (int i = 1; i < 9; i++)
		for (int j = 0; j < 82; j++)
			for (int k = 0; k < 10; k++)
				a[i + 1][j + k] += a[i][j];
	for (int i = 1; i < 10; i++)
		for (int j = 1; j < 10; j++)
			if (s - j >= 0)
				res += a[i - 1][s - j];
	if (s == 1) res++;
	printf("%d\n", res);
	return 0;
}
