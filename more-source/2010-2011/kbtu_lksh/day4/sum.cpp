#define file "sum"
#include <cstdio>
#include <cstdlib>
#include <set>
#include <ctime>
#include <iostream>

using namespace std;

int M;
struct node {
    int x, y, cnt;
    node *l, *r;
}nodes[300100];

node *New(int x) {
    M++; nodes[M].x = x; nodes[M].cnt = x;
    nodes[M].y = (rand() << 16) | rand();
    return &nodes[M];
}

int cnt(node *v) {
    if (!v) return 0;
    return v->cnt;
}

void update(node *v) {
    if (!v)return ;
    v->cnt = v->x + cnt(v->l) + cnt(v->r);
}

void split (node *t, int x, node *&l, node *&r) {
    if (!t) l = r = 0;
    else if (t->x <= x)
        split(t->r, x, t->r, r), l = t;
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

bool find(node *v, int x) {
    while(v) {
        if (v->x == x)
            return 1;
        if (v->x < x)
            v = v->r;
        else v = v->l;
    }
    return 0;
}

int last;
node *t, *A, *B, *C;
int main() {
    freopen(file ".in", "r", stdin);
    freopen(file ".out", "w", stdout);
    srand(2314654);
    int n, m; char c;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        scanf("%c ", &c);
        if (c == '+') {
            scanf("%d\n", &m);
            m = (last + m);
            if (m >= 1000000000)
                m -= 1000000000;
            if (find(t, m)) continue;
            A = New(m);
            split(t, m - 1, t, C);
            merge(t, A, t);
            merge(t, C, t);
            last = 0;
        }
        else {
            int x, y;
            scanf("%d %d\n", &x, &y);
            split(t, y, t, C);
            split(t, x - 1, A, B);
            last = cnt(B);
            printf("%d\n", last);
            merge(A, B, t); merge(t, C, t);
        }
    }
    return 0;
}

