#include <cstdio>
#include <iostream>

using namespace std;

#ifdef WIN32
#define i64 "%I64d"
#else
#define i64 "%lld"
#endif

const int maxn = 200009;
int A, B, C, t, n, ltop, rtop, nl, nr,
    newval, p = 1000000007;
int l[maxn], r[maxn];
long long ans;

void swap (int &a, int &b)
{
    int t = b;
    b = a;
    a = t;
}

void downHeap(int a[], int k, int n) {
  --n;
  int new_elem;
  int child;
  new_elem = a[k];

  while(k <= n/2) {
    child = 2*k;
    if( child < n && a[child] < a[child+1] )
    child++;
    if( new_elem >= a[child] ) break;
    a[k] = a[child];
    k = child;
  }
  a[k] = new_elem;
}

void poph(int a[], int n)
{
    swap (a[0], a[n - 1]);
    downHeap(a, 0, n - 1);
}

void pushh(int a[], int n)
{
    int cur = n - 1;
    while (cur && a[cur/2] < a[cur])
    {
        swap(a[cur], a[cur/2]);
        cur /= 2;
    }
}


int main ()
{
//    scanf ("%d", &t);
cin >>t;
    for (int L = 1; L <= t; L++)
    {
        nl = 1; nr = 0;
//        scanf ("%d%d%d%d", &A, &B, &C, &n);
cin >> A >> B >> C >> n;
        l[0] = 1;ans = 1;
        for (int i = 2; i <= n; i++)
        {
            newval = (1ll * l[0] * A + 1ll * B * i + C) % p;

            ans += newval;

            if (i % 2 == 0)
            {
                l[nl++] = newval;
                pushh(l, nl);
                ltop = l[0];
                poph(l, nl);
                nl--;
                r[nr++] = -ltop;
                pushh(r, nr);
            }
            else
            {
                r[nr++] = -newval;
                pushh(r, nr);
                rtop = -r[0];
                poph(r, nr);
                nr--;
                l[nl++] = rtop;
                pushh(l, nl);
            }
        }
//        printf (i64"\n", ans);
cout << ans <<"\n";
    }

    return 0;
}

