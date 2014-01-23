// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
/*
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <string>
#include <cstring>
*/

using namespace std;

/*
#define pb(x) push_back(x)
#define mp(x) make_pair(x)
#define sz(x) x.size()
#define min(x,y) (x<y?x:y)
#define max(x,y) (x>y?x:y)
#define all(x) (x.begin(),x.end())
*/

// solving must start here

int x, ans = 0;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%d", &x);

    if (x-3 <= 0)
    {
        printf("0");
        return 0;
    }

    for (int a = x-3; a > 0; a--)
        for (int b = a; b > 0; b--)
            for (int c = b; x-a-b-c <= c && c > 0; c-- )
                if(x-a-b-c > 0)ans++;

    printf ("%d", ans);

    return 0;
}

