//ioi2009 review
//solution by Kim Vyacheslav
#include <cstdio>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

#define DEBUG
#define MAXN 500000
#define i64 __int64

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)

int n;
i64 w;
struct hire
{
    double u, s, q;
    int i;
    bool operator < (const hire & r) const
    {   return u < r.u; }
}a[MAXN];
vector <double> heap;
bool ans[MAXN];
vector< pair<double, int> >newheap;
int currentnum, maxnum, besti;
double totalqual, maxqual, cost, mincost;



void input()
{
    scanf("%d %lld", &n, &w);
    int i;
    for(i = 0; i < n; i++)
    {
        scanf("%lf%lf", &a[i].s, &a[i].q);
        a[i].u = a[i].s / a[i].q;
        a[i].i = i;
    }
    sort(a, a+n);
    
}

void solve()
{    
    for(int i = 0; i < n; i++)
    {
        heap.pb(a[i].q);
        push_heap(heap.begin(), heap.end());
        totalqual += a[i].q;
        maxqual = w / a[i].u;
        
        while(totalqual > maxqual)
        {
            totalqual -= heap[0];
            pop_heap(heap.begin(), heap.end());
            heap.pop_back();
        }
        
        currentnum = heap.size();
        cost = totalqual * a[i].u;
        if(currentnum > maxnum || (currentnum == maxnum && mincost > cost))
        {
            besti = i;
            maxnum = currentnum;
            mincost = cost;
        }
    }
    
    totalqual = 0;
    for(int i = 0; i <= besti; i++)
    {
        newheap.pb(mp(a[i].q, a[i].i));
        push_heap(newheap.begin(), newheap.end());
        totalqual += a[i].q;
        ans[a[i].i] = true;
    }
    
    maxqual = w / a[besti].u;    
    while(totalqual > maxqual)
    {
        totalqual -= newheap[0].first;
        ans[newheap[0].second] = 0;
        pop_heap(newheap.begin(), newheap.end());
        newheap.pop_back();
    }
    
}

void output()
{
    printf("%d\n", maxnum);
    for(int i = 0; i < n; i++)
        if(ans[i])
            printf("%d\n", i+1);
}

int main ()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    input();
    solve();
    output();
    
    return 0;
}

