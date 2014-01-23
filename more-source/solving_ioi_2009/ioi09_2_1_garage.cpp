//ioi 2009 review
//solution by Kim Vyacheslav
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <deque>
using namespace std;

#define DEBUG

#define MAXN 101
#define MAXM 2001

int n, m, r[MAXN], w[MAXM];
int ffp = 0, places[MAXM];
bool taken[MAXN];
long long answer = 0;
deque<int>q;

void input()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &r[i]);
    for(int i = 0; i < m; i++)
        scanf("%d", &w[i]);
}

void solve()
{
    int x;
    for(int i = 0; i < 2*m; i++)
    {
        scanf("%d", &x);
        if(q[i] > 0)
        {
            x--;
            q.push_back(x);
        }
        else
        {
            x = -x - 1;
            taken[places[q[i]]] = 0;
            if(places[q[i]] < ffp)ffp = places[q[i]];
        }
        while(!q.empty() && ffp < n)
        {
            taken[ffp] = 1;
            places[q.front()] = ffp;
            answer += r[ffp] * w[q.front()];
            q.pop_front();
            while(taken[ffp])ffp++;
        }
    }
}

void output()
{
    printf("%lld", answer);
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

