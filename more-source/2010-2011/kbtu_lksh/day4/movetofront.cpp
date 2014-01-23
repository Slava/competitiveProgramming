#define file "movetofront"
#include <cstdio>
#include <cstdlib>

int M;
struct node {
    int x, y, cnt;
    node *l, *r;
}nodes[100100];

node *New(int x) {
    M++; nodes[M].x = x;
    nodes[M].y = (rand() << 16) | rand();
    return &nodes[M];
}

int cnt(node *v) {
    if (!v) return 0;
    return v->cnt;
}

void update(node *v) {
    if (!v)return ;
    v->cnt = 1 + cnt(v->l) + cnt(v->r);
}

void split (node *t, int x, node *&l, node *&r) {
    if (!t) l = r = 0;
    else if (cnt(t->l) + 1 <= x)
        split(t->r, x - cnt(t->l) - 1, t->r, r), l = t;
    else split(t->l, x, l, t->l), r = t;
    update(t);
}

void merge (node *l, node *r, node *&t) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->y > r->y)
        merge(l->r, r, l->r), t = l;
    else merge(l, r->l, r->l), t = r;
    update(t);
}

void show(node *v) {
    if (!v)return ;
    show(v->l);
    printf("%d ", v->x);
    show(v->r);
}

node *t, *A, *B, *C;
int main() {
    freopen(file ".in", "r", stdin);
    freopen(file ".out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        A = New(i);
        merge(t, A, t);
    }
//    show(t); printf("\n");
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        split(t, y, t, C);
        split(t, x - 1, A, B);
        merge(B, A, t);
        merge(t, C, t);
//        show(t); printf("\n");
    }
    show(t);
    return 0;
}

