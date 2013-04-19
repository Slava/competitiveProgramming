#include <cstdio>
#include <cstdlib>

char d[5][5], s[5];
int a[4][4], b[4][4], ans = (1 << 30);

void apply(int x, int y) {
	x--; y--;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (d[i][j] == '1' && 
				x + i >= 0 && y + j >= 0 && 
				x + i < 4 && y + j < 4)
				b[x + i][y + j] ^= 1;
}

void go(int m) {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			b[i][j] = a[i][j];
	int h = 0;
	for (int i = 0; i < 16; i++)
		h += (m >> i) & 1;
	for (int i = 0; i < 16; i++, m >>= 1)
		if (m & 1)
			apply(i / 4, i % 4);
	int s = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			s += b[i][j];
	if (!s || s == 16)
		if (ans > h)
			ans = h;
}

int main() {
	for (int i = 0; i < 4; i++) {
		scanf("%s", s);
		for (int j = 0; j < 4; j++)
			a[i][j] = s[j] == 'B';
	}
	for (int i = 0; i < 3; i++)
		scanf("%s", d[i]);
	for (int i = 0; i < (1 << 16); i++)
		go(i);
	if (ans == (1 << 30))
		printf("Impossible\n");
	else printf("%d\n", ans);
	return 0;
}
