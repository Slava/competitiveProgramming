#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define abs(x) ((x)<0?(x):-(x))
#define mp make_pair
#define x first
#define y second

vector < pair<int, pair<int, int> > >heap;
vector < pair<int, int> >ans;
int N, a[1000009], n[1000009], p[10000009], u[10000009];
char g[10000009];

int fn (int x)
{
    if (u[n[x]])
        n[x] = fn (n[x]);
    return n[x];
}

int fp (int x)
{
    if (u[p[x]])
        p[x] = fp (p[x]);
    return p[x];
}

int main ()
{
    scanf ("%d%s", &N, g);

    for (int i = 0; i < N; i++)
    {
        scanf ("%d", &a[i]);
        p[i] = i - 1;
        n[i] = i + 1;
    }
    for (int i = 1; i < N; i++)
        if (g[i] != g[i - 1])
            heap.push_back(mp(abs(a[i] - a[i - 1]), mp(-i + 1, -i)));
    make_heap(heap.begin(), heap.end());
    while (heap.size())
    {
//        printf ("Cur %d %d %d\n", heap.begin()->x,heap.begin()->y.x,heap.begin()->y.y);getchar();
        int A, B;
        A = -heap.begin()->y.y;
        B = -heap.begin()->y.x;
        pop_heap(heap.begin(), heap.end());
        heap.pop_back();
        if (u[A] || u[B])
            continue;
        u[A] = u[B] = 1;
        ans.push_back(mp(A, B));
        A = fp(A);
        B = fn(B);
        if (A != -1  && B != N)
            if (g[A] != g[B])
            {
                heap.push_back (mp(abs(a[A] - a[B]), mp(-A, -B)));
                push_heap(heap.begin(), heap.end());
            }
    }

    printf ("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++)
        printf ("%d %d\n", ans[i].y + 1, ans[i].x + 1);

    return 0;
}





// lang: GNU C++
// memory: 101900 KB
// author: imslavko
// submit_date: Nov 24, 2010 7:28:24 AM
// contest: 45
// link: /contest/45/submission/196143
// time: 330 ms
// verdict: Accepted
// problem: 45C - Dancing Lessons
// ID: 196143
// downloaded by very stupid script
