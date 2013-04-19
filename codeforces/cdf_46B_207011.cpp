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





// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Dec 5, 2010 11:21:59 AM
// contest: 46
// link: /contest/46/submission/207011
// time: 30 ms
// verdict: Accepted
// problem: 46B - T-shirts from Sponsor
// ID: 207011
// downloaded by very stupid script
