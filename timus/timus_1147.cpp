#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

bool keep[32000];
struct Heap {
	priority_queue<int> q;
	void push(int x) {
		if (keep[x])
			keep[x] = false;
		else
			q.push(x);
	}

	int top() {
		int x;
		while (true) {
			x = q.top();
			if (!keep[x])
				break;
			keep[x] = false;
			q.pop();
		}

		return x;
	}

	void erase(int x) {
		if (!keep[x])
			keep[x] = true;
	}
} h;

struct po { int n; bool o; }Y;
po b[4009]; int a[4009];
int pr, rp, col[2550], A, B; 
int res[2550], diff, fed;
int x[2][2001], y[2][2001], n, mm, nn;

int inInt() {
	int x;
	scanf("%d", &x);
	return x;
}

bool operator < (po a, po b) {
	if (y[a.o][a.n] == y[b.o][b.n]) return b.o;
	return y[a.o][a.n] < y[b.o][b.n];
}

int main() {
	A = inInt(); B = inInt(); n = inInt();
	for (int i = 1; i <= n; i++) {
		x[1][i] = inInt();
		y[1][i] = inInt();

		x[0][i] = inInt();
		y[0][i] = inInt();

		col[i] = inInt();
		a[mm++] = x[1][i]; a[mm++] = x[0][i];
	}
	x[0][0] = A; y[0][0] = B; col[0] = 1; a[mm++] = B;
	sort(a, a + mm); 
	mm = unique(a, a + mm) - a;

	for (int *j = a; j != a + mm; j++) {
		nn = 0; rp = -1;
		for (int i = 0; i <= n; i++)
			if (*j > x[1][i] && *j <= x[0][i]) {
				b[nn].n = i;
			   	b[nn].o = 1;
				nn++;
			   	b[nn].n = i;
			   	b[nn].o = 0;
				nn++;
			}
		stable_sort(b, b + nn); 
		
		diff = *j - pr;

		for (int i = 0; i < nn; i++) {
			if (rp != -1) {
				fed = y[b[i].o][b[i].n] - rp;
				res[col[h.top()]] += fed * diff;
			}
			if (b[i].o)
				h.push(b[i].n);
			else h.erase(b[i].n);
			rp = y[b[i].o][b[i].n];
		}

		pr = *j;
	}

	int s = 0;
	for (int i = 2; i < 2550; i++)
		s += res[i];

	if (s != A * B)
		printf("1 %d\n", A * 1 * B - s);
	for (int i = 2; i < 2550; i++)
		if (res[i] > 0) 
			printf("%d %d\n", i, res[i]);

	return 0;
}

