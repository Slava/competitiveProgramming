#include <cstdio>

const int NN = 100001;

unsigned short ne[NN];
int x[NN], he[1001];
int m;

void alloc(int St, int X) {
	x[m] = X<<1;
	x[m] += he[St]&1;
	ne[m] = he[St]/2;
	he[St] = ++m;
}

int popst(int St) {
	int X = x[he[St]-1];
	he[St] = ne[he[St]-1]<<1;
	he[St] += X&1;
	return X/2;
}

int main() {
	int n, St, x;
	scanf("%d", &n);
	char s[5];
	while(n--) {
		scanf("%s", s);
		if (s[1]=='U') {
			scanf("%d%d", &St, &x);
			alloc(St-1,x);
		} else {
			scanf("%d", &St);
			printf("%d\n", popst(St-1));
		}
	}	
	return 0;
}
