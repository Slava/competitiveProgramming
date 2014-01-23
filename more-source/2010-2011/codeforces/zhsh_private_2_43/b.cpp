// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>

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

int main ()
{
    int a[6], n, prior[] = {0, 1, -1, 2, -2, 3, -3, 4, -4, 5, -5}, wanna;
    char s[5][5] = {"S", "M", "L", "XL", "XXL"}, want[6];

    for (int i = 0; i < 5; i++)
        scanf ("%d", &a[i]);
    scanf ("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf ("%s", want);
        for (int j = 0; j < 5; j++)
            if (strcmp (want, s[j]) == 0)
            {
                wanna = j;
                break;
            }
        for (int j = 0; j < 11; j++)
            if (wanna + prior[j] >= 0 && wanna + prior[j] < 5 && a[wanna + prior[j]])
            {
                a[wanna + prior[j]]--;
                printf ("%s\n", s[wanna + prior[j]]);
                break;
            }

    }

    return 0;
}

