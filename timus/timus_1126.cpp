#include <cstdio>
#include <cstdlib>

struct stack {
	int a[25601], b[25601], n;
	void push(int x) {
		a[n] = x;
		if (!n || b[n - 1] < x)
			b[n] = x;
		else b[n] = b[n - 1];
		n++;
	}
	int pop() { return a[--n]; }
	int max() { return n ? b[n - 1] : 0; }
};

struct queue {
	stack a, b;
	void push(int x) { a.push(x); }
	void pop() {
		if (!b.n)
		while (a.n) {
			b.push(a.pop());
		}
		b.pop();
	}
	int max() {
		if (!b.n)
		while (a.n) {
			b.push(a.pop());
		}
		return (a.max() > b.max() ? a.max() : b.max());
	}
} a;
int x, m;

int main (){
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &x);
		a.push(x);
	}
	printf ("%d\n", a.max());
	for (; scanf("%d", &x) == 1;) {
		if (x == -1)
			break;
		a.pop(); a.push(x);
		printf("%d\n", a.max());
	}
	return 0;
}


