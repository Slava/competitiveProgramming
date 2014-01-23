#include <cstdio>
#include <cstdlib>
#define fi(x) (x + N)

const int N = 2000;
int p[N * 2];

int findSet (int x){
	if (p[x] != x)
		return p[x] = findSet(p[x]);
	return p[x];
}

void unite (int x, int y){
	x = findSet(x);
	y = findSet(y);
	if (rand() & 1)
		p[x] = y;
	else p[y] = x;
}

void move (int x, int y){
	p[x] = y;
}

int main (){
	for (int i = 0; i < N; i++)
		p[i] = p[fi(i)] = fi(i);
// 1 - find, 2 - unite, 3 - move
	for(int cmd, x, y;;){
		scanf("%d", &cmd);
		if (cmd == 1){
			scanf("%d", &x);
			printf("findSet(%d) = %d\n", x, findSet(x));
		}
		else if (cmd == 2){
			scanf("%d%d", &x, &y);
			unite(x, y);
		}
		else {
			scanf("%d%d", &x, &y);
			move(x, y);
		}
	}
	return 0;
}

