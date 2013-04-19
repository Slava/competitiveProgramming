// Kim Vyacheslav Karaganda KTL
// 2011
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

char S;int n, ans;
string st[2000];
int main ()
{
    while (cin >> S)
    {
        if (S == '.')
        {
            if (n){
                for (int i = 0; i < n; i++)
                    if (st[i] == st[n])
                        ans++;
                st[n] = "";
                n--;}
        }else
        if (S == ':')
        {
            n++;
        }else
        if  (S == ',')n++;
        else st[n].push_back(S);
    }

    cout << ans;
    return 0;
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Jan 21, 2011 7:38:40 PM
// contest: 56
// link: /contest/56/submission/257434
// time: 30 ms
// verdict: Accepted
// problem: 56C - Corporation Mail
// ID: 257434
// downloaded by very stupid script
