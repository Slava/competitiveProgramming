#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct node {
	int x, y, size, pl;
	node *l, *r;
	node(int X) {
		y = rand();
		x = X;
		l = r = 0;
		size = 1;
		pl = 0;
	}
};

int key(node *v) {
	return v ? v->x + v-> pl : 0;
}

int size(node *v) {
	return v ? v->size : 0;
}

void push(node *v) {
	if (!v)return;
	if (v->l) v->l->pl += v->pl;
	if (v->r) v->r->pl += v->pl;
	v->x += v->pl;
	v->pl = 0;
}

void upd(node *v) {
	if (!v) return;
	v->size = 1 + size(v->l) + size(v->r);
}

void split(node *t, int x, node *&l, node *&r) {
	push(t);
	if (!t)
		l = r = 0;
	else if (key(t) <= x)
		split(t->r, x, t->r, r), l = t;
	else split(t->l, x, l, t->l), r = t;
	upd(l); upd(r);
}

void splitImp(node *t, int x, node *&l, node *&r) {
	push(t);
	if (!t)
		l = r = 0;
	else if (size(t->l) + 1 <= x)
		splitImp(t->r, x-size(t->l)-1, t->r, r), l = t;
	else splitImp(t->l, x, l, t->l), r = t;
	upd(l); upd(r);
}

void merge(node *l, node *r, node *&t) {
	push(l); push(r);
	if (!l || !r)
		t = l ? l : r;
	else if (l->y > r->y)
		merge(l->r, r, l->r), t = l;
	else merge(l, r->l, r->l), t = r;
	upd(l); upd(r);
}

int leftMostKey(node *v) {
	if (!v) return 0;
	push(v);
	if (!v->l)
		return v->x;
	return leftMostKey(v->l);
}

void out(node *t, int add=0, int setw = 0) {

	if (!t)return;
	out(t->l,add+t->pl,setw+1);
	for (int i = 0; i < setw; i++)printf(" ");
	printf("node x:%d size:%d pl:%d+add %d\n", t->x, size(t), t->pl, add);
	out(t->r,add+t->pl,setw+1);
}

node *t;
void fertilize(int c, int h) {
	node *v, *u, *v1, *u1, *A, *B;
	v = u = v1 = u1 = 0;
	split(t, h-1, A, B);
	t = A; v = B;
	if (false) {
	puts("splited");fflush(stdout);

	}
	splitImp(v, c, A, B);
	v = A; u = B;
	if(v)v->pl++;
	int k = leftMostKey(u);
	split(u, k, u1, u);
	split(v, k, v, v1);
	merge(u1, v1, u1);
	merge(u1, u, u);
	merge(v,u,v);
	merge(t,v,t);
}

int solve(int min, int max) {
	node *v, *u;
	v = u = 0;
	split(t, min-1, t, v);
	split(v, max, v, u);
	int ret = size(v);
	merge(v, u, v);
	merge(t, v, t);
	return ret;
}

int n, m, a[100100];
char cmd[100];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", a+i);
	sort(a,a+n);
	if (n * 1LL * m <= 3000000LL) {

		for (int i = 0; i < m; i++) {
			int x, y;
			scanf("%s%d%d", cmd, &x, &y);
			if (cmd[0] == 'F')
				for (int j = 0; j < n && x > 0; j++)
					if (a[j] >= y) {
						a[j]++; x--;
					}
			if (cmd[0] == 'C') {
				int res = 0;
				for (int j = 0; j < n; j++)
					if (a[j] >= x && a[j] <= y)
						res++;
				printf("%d\n", res);
			}
			sort(a,a+n);
		}
		return 0;
	}

	for (int i = 0; i < n; i++)
		merge(t,new node(a[i]),t);

	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%s%d%d", cmd, &x, &y);
		if (cmd[0] == 'F')
			fertilize(x,y);
		if (cmd[0] == 'C') 
			printf("%d\n", solve(x,y));
	}

	return 0;
}


