#include <cstdio>
#include <algorithm>

using namespace std;

char a[] = "abc";
int n;
int main() {
	scanf("%d", &n);
	if (6 * n > 100000)
		printf("TOO LONG\n");
	else if (n == 1)
		printf("a\nb\nc\n");
	else do {
		for (int i = 0; i < n; i++)
			printf("%c", a[i % 3]);
		printf("\n");
	} while (next_permutation(a, a + 3));
	return 0;
}
