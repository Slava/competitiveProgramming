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


#define pb(x) push_back(x)
#define mp(x) make_pair(x)
#define sz(x) x.size()
#define min(x,y) (x<y?x:y)
#define max(x,y) (x>y?x:y)
#define all(x) (x.begin(),x.end())

#define file ""
int ans;
int main ()
{
    int n;
    string bad[] = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};
    string a[200];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        int isnum = 1;
        for (int j = 0; j < a[i].size(); j++)
            isnum &= a[i][j] >= 48 && a[i][j] <= '9';
        if (isnum)
        {
            int num = 0;
            for (int j = 0; j < a[i].size(); j++)
            {
                num *= 10;
                num += a[i][j] - 48;
            }
            if(num < 18)
                ans++;
        }
        else
            for (int j = 0; j < 11; j++)
                if (a[i] == bad[j])
                {
                    ans++;
                }

    }

    cout << ans;

    return 0;
}





// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Jan 21, 2011 8:33:25 PM
// contest: 56
// link: /contest/56/submission/258296
// time: 30 ms
// verdict: Accepted
// problem: 56A - Bar
// ID: 258296
// downloaded by very stupid script
