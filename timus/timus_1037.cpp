#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int,int> ii;
priority_queue <int> q;
priority_queue <ii> qt;

const int N = 30100;
bool freeM[N];
char query[10];
int lastAccessed[N];
int time, block;

int main() {
	memset(freeM, 1, sizeof freeM);
	for (int i = 1; i <= N; i++)
		q.push(-i);

	while (~scanf("%d%s", &time, query)) {
		while (!qt.empty() && -qt.top().first + 600 <= time) {
			int v = qt.top().second;
			qt.pop();
			if (lastAccessed[v] + 600 > time)
				continue;
			freeM[v] = 1;
			q.push(-v);
		}

		if (query[0] == '+') {
			int v = 1;
			while (!freeM[v]) {
				v = -q.top();
				q.pop();
			}

			freeM[v] = 0;
			printf("%d\n", v);
			qt.push(ii(-time, v));
		} else {
			scanf("%d", &block);
			if (freeM[block])
				printf("-\n");
			else {
			  	printf("+\n");
				lastAccessed[block] = time;
				qt.push(ii(-time, block));
			}
		}
	}

	return 0;
}
