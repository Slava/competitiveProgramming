#include <cstdio>
#include <cstdlib>

void solve() {
	int sum = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 26; j++)
			for (int k = 0; k < 26; k++)
				sum += rand();
	printf("%d\n", sum);
}

int main() {
	int t = 10000;
	for (int i = 0; i < t; i++)
		solve();
}
