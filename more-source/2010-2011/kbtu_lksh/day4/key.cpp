#include <cstdio>
#include <cstdlib>
#define max(a,b) (a>b?a:b)

const int N = 300000;
int M, p[N], n, m;
struct node {
    int x, y, cnt;
    node *l, *r;
}nodes[N];

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

int T[N], a[N];
void inc(int i) {
    for (; i < N; i |= i + 1)
        T[i]++;
}
int sum(int i) {
    int r = 0;
    for (; i >= 0; i &= i + 1, i--)
        r += T[i];
    return r;
}
int sum(int l, int r) { return sum(r) - sum(l - 1); }

void unite(int i, int j) {
    p[i] = j;
}
int get(int x) {
    if (p[x] != x)
        p[x] = get(p[x]);
    return p[x];
}

node *t, *A, *B;
int main() {
    freopen("key.in", "r", stdin);
    freopen("key.out", "w", stdout);
    for (int i = 0; i < N; i++)
        p[i] = i;
    scanf("%d%d", &n, &m);
    for (int k = 1; k <= n; k++) {
        int x; scanf("%d", &x);
        if (!a[x]) {
            a[x] = 1;
            unite(x, x + 1);
            int pp = sum(x - 1);
            split(t, pp, t, B);
//            printf("\npp = %d", pp);printf("\nt: ");show(t); printf("\nB:");show(B);
            A = New(k);
            merge(t, A, t); merge(t, B, t);
            inc(x);
        }
        else {
            int pos = get(x), pp;a[pos] = 1;
            pp = sum(x - 1);
            inc(pos); unite(pos, pos + 1);
            split(t, pp, t, B);
//            printf("\npp = %d", pp);printf("\nt: ");show(t); printf("\nB:");show(B);
            A = New(k);
            merge(t, A, t); merge(t, B, t);
        }
//        printf("\nfinal t: ");show(t);puts("");
    }
//    show(t);
    int last = 0;
    for (int i = 1; i < N; i++)
        if (a[i])
            last = i;
    printf("%d\n", last);
    for (int i = 1; i <= last; i++) {
        if (!a[i])printf("0 ");
        else {
            split(t, 1, A, t);
            show(A);
        }
    }
    return 0;
}
