#include <cstdio>
#include <cstring>
const int N = 1000000;
bool u[N + 9];
char s[N + 9];
int t[N], n, b[209];
struct node;
typedef node* tnode;
struct node {
	int i;
	tnode next, prev;
	node() { i = 0; next = prev = 0; }
	node(int _i) { i = _i; next = prev = 0; }
};
struct list {
	tnode b, e;
	int m;
	list() { m = 0; b = e = 0; }
	void add(tnode t) {
		if (m == 0) {
			e = t;
			b = e;
			b->next = e; b->prev = 0;
			e->prev = b; e->next = 0;
		}
		else {
			e->next = t;
			t->prev = e;
			e = t; e->next = 0;
		}
		m++;
   	}
} a[200];

void inc (int i, int x)
{
	i--;
	for (; i < n; i += i & -i)
		t[i] += x;
}

int sum (int i)
{
	i--;
	int r = 0;
	for (; i >= 0; i -= i & -i)
		r += t[i];
	return r;
}

int find (int i)
{
	return sum(i) - sum(i - 1);
}

int main ()
{
    int i, l, r, ll, rr, i1, i2, j1, j2, ib, ie, jb, je;
    long long ans = 0;
	scanf("%s", s);
	n = strlen(s);
	for (i = 0; i < n; i++)
		a[s[i]].add(new node(i));
    int ch = 0;
    for (i = 'a'; i <= 'z'; i++) {
        if (a[i].m % 2) {
            ch++;
            b[i] = 1;
        }
    }
    tnode t = 0;
    if (ch > 1) printf("-1");
    else {
        l = ll = 0; r = rr = n - 1;
        for ( ; ll < rr && l < r; ll++, rr--) {
            do {
                while (u[l] && l < r) l++;
                while (u[r] && l < r) r--;
                if (l < r && s[l] == s[r]) {
                    l++, r--;
                    ll++, rr--;
                }
                else
                    break;
            } while (l < r);
            if (l < r) {
                i1 = a[s[l]].b->i;
                if (a[s[l]].m > 1)
                    i2 = a[s[l]].e->i;
                else
                    i2 = 0;
                j2 = a[s[r]].e->i;
                if (a[s[r]].m > 1)
                    j1 = a[s[r]].b->i;
                else
                    j1 = n - 1;
                ib = find(i1 + 1) - 1;
                ie = find(i2 + 1) - 1;
                jb = find(j1 + 1) - 1;
                je = find(j2 + 1) - 1;
                if (rr - ie < jb - ll) {
                    ans += (rr - ie) * 1ll;
                    u[i1] = u[i2] = 1;
                    a[s[l]].m -= 2;
                    if (a[s[l]].m < 1)
                        a[s[l]].b = a[s[l]].e = 0;
                    else  {
                        a[s[l]].b = a[s[l]].b->next;
                        a[s[l]].e = a[s[l]].e->prev;
                    }
//                    add(i2 + 2, n, -1);
					for (int k = i2; k <= n; k++)
						inc(k, -1);
                    l++;
                }
                else {
                    u[j1] = u[j2] = 1;
                    ans += (jb - ll) * 1ll;
                    a[s[r]].m -= 2;
                    if (a[s[r]].m < 1)
                        a[s[r]].b = a[s[r]].e = 0;
                    else {
                        a[s[r]].b = a[s[r]].b->next;
                        a[s[r]].e = a[s[r]].e->prev;
                    }
//                    add(1, j1, 1);
					for (int k = 1; k <= j1; k++)
						inc(k, 1);
                    r--;
                }
            }
        }
        printf("%lld", ans);
    }
}




