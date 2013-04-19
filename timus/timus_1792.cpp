#include <cstdio>
#include <cstdlib>

int a[10];
bool good() {
	return 
		a[4] == (a[1] ^ a[2] ^ a[3]) &&
		a[5] == (a[0] ^ a[2] ^ a[3]) &&
		a[6] == (a[0] ^ a[1] ^ a[3]);
}

int main() {
	for (int i = 0; i < 7; i++)
		scanf("%d", a + i);
	for (int i = 0; i < 8; i++) {
		a[i] ^= 1;
		if (good()) {
			for (int j = 0; j < 7; j++)
				printf("%d ", a[j]);
			return 0;
		}
		a[i] ^= 1;
	}
	return 0;
}
