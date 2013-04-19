#include <cstdio>
#include <cstdlib>

const int N = 163848;
bool np[N];
int p[15001], n, k, x;

int main() {
	for (int i = 2; i < N; i++)
		if (!np[i]) {
			p[n++] = i;
			for (int j = i + i; j < N; j += i)
				np[j] = 1;
		}

	scanf("%d", &k);
	while (k--) {
		scanf("%d", &x);
		printf("%d\n", p[x-1]);
	}
	return 0;
}
