#include <cstdio>
#include <cstdlib>
#include <queue>

int a, g[] = {19, 39, 78, 140, 305, 626, 1252, 2248, 4880, 10016, 2032, 35968, 12544, 29184, 58368, 51200}, u[1 << 16];
char s[2000];
/* START */
int main (){
	for (int i = 0; i < 4; i++) {
		scanf("%s", s);
		for (int j = 0; j < 4; j++)
			if (s[j] == 'b')
				a |= 1 << (i * 4 + j);
	}
	u[a] = 1;
	std::queue<int>q;q.push(a);
	while (!q.empty()) {
		a = q.front(); q.pop();
		if (!a || a == (1 << 16) - 1) {
			printf("%d\n", u[a] - 1);
			return 0;
		}
		for (int i = 0; i < 16; i++) {
			int v = a ^ g[i];
			if (!u[v]) {
				u[v] = u[a] + 1;
				q.push(v);
			}
		}
	}
	printf("Impossible");
	return 0;
}

/*
0123
4567
8901
2345
*/
