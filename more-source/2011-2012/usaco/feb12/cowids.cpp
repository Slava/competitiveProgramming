#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

typedef long long Int;

Int c[30000][12], N, K;

int main() {
	freopen("cowids.in", "r", stdin);
	freopen("cowids.out", "w", stdout);

	c[0][0] = 1;
	for (int i = 1; i < 30000; i++) {
		for (int j = 0; j < 11; j++) {
			if (!j) c[i][j] = 1;
			else c[i][j] = c[i-1][j] + c[i-1][j-1];
		}
	}
	cin >> N >> K;
	
	if (K == 1) {
		printf("1");
		for (int i = 1; i < N; i++)
			printf("0");
		puts("");
		return 0;
	}

	int len = K, left = K;
	while (N > c[len-1][K-1]) {
		N -= c[len-1][K-1];
		len++;
	}

	left--;
	printf("1");
	for (int i = len-1; i > 0; i--)
		if (left < i) {
			if (N > c[i-1][left]) {
				printf("1");
				N -= c[i-1][left];
				left--;
			}
			else printf("0");
		} else {
			printf("1");
			left--;
		}

	puts("");

	return 0;
}
