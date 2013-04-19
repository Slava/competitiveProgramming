#include <cstdio>
#include <queue>

using namespace std;

int a, b, c;
bool u[256][256][256], can[256 * 3];
queue<int>q;

void go(int x, int y, int z) {
	if (x < 0 || y < 0 || z < 0 || x > a || y > b || z > c || u[x][y][z])
		return;
	u[x][y][z] = 1;
	q.push(x | (y << 8) | (z << 16));
}

int main() {
	scanf("%d%d%d", &a, &b, &c);
	q.push(0);
	u[0][0][0] = 1;
	while(!q.empty()) {
		int v, x, y, z;
		v = q.front(); q.pop();
		x = v & 255; v >>= 8; y = v & 255; v >>= 8;	z = v;
//		printf(">>> %d %d %d\n", x, y, z);
		can[x] = can[y] = can[z] = can[x + y] = can[x + z] = can[y + z] = can[x + y + z] = 1;
		go(a, y, z);
		go(x, b, z);
		go(x, y, c);
		go(0, x + y, z);
		go(x + y, 0, z);
		go(x, 0, y + z);
		go(x, y + z, 0);
		go(x + z, y, 0);
		go(0, y, x + z);
		go(x + y - b, b, z);
		go(a, x + y - a, z);
		go(x + z - c, y, c);
		go(a, y, z + x - a);
		go(x, z + y - c, c);
		go(x, b, z + y - b);
	}
	int ans = 0;
	for (int i = 1; i <= a + b + c; i++)
		if (can[i])
			ans++;
	printf("%d", ans);
	return 0;
}

