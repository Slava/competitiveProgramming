#include <cstdio>
#include <cstdlib>

int a[3][3], A[40000], B[40000];
char s[4];

int hash(int t) {
	int r = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			r *= 3;
			r += (a[i][j] == 4 ? 2 : a[i][j]);
		}
	return r + (t == 1 ? 20000 : 0);
}

int f(int t) {
	int h = hash(t);
	if (B[h])return A[h];
	B[h] = 1;
	for (int i = 0; i < 3; i++) {
		if (a[i][0] + a[i][1] + a[i][2] == 3)
			return A[h] = 1;
		if (a[0][i] + a[1][i] + a[2][i] == 3)
			return A[h] = 1;
		if (a[i][0] + a[i][1] + a[i][2] == 12)
			return A[h] = 4;
		if (a[0][i] + a[1][i] + a[2][i] == 12)
			return A[h] = 4;
	}
	if (a[0][0] + a[1][1] + a[2][2] == 3)
		return A[h] = 1;
	if (a[0][0] + a[1][1] + a[2][2] == 12)
		return A[h] = 4;
	if (a[0][2] + a[1][1] + a[2][0] == 3)
		return A[h] = 1;
	if (a[0][2] + a[1][1] + a[2][0] == 12)
		return A[h] = 4;
	int sum = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			sum += !!a[i][j];
	if(sum == 9)return A[h] = 3;
	int pr = t == 1 ? 4 : 1;
	A[h] = pr;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (!a[i][j]) {
				a[i][j] = t;
				if (f(pr) == 3 && A[h] == pr)
					A[h] = 3;
				else if (f(pr) == t)
					A[h] = t;
				a[i][j] = 0;
			}
	return A[h];
}

/* START */
int main (){
	f(1);
	for (int i = 0; i < 3; i++) {
		scanf("%s", s);
		for (int j = 0; j < 3; j++)
			if (s[j] == 'X')
				a[i][j] = 1;
			else if (s[j] == 'O')
				a[i][j] = 4;
	}
	int z = f(1);
	if (z == 1)printf("Crosses win");
	else if (z == 4)printf("Ouths win");
	else printf("Draw");
	return 0;
}
