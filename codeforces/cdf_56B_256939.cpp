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

int n;
vector<int> a,b;

int main ()
{
    cin >> n;
    a.resize(n);b.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = i + 1;
    }

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            for (int k = 0; k <= (j - i) / 2; k++)
                swap (a[i+k], a[j-k]);
            if (a == b)
            {
                cout << i + 1 << " " << j + 1;
                return 0;
            }
            for (int k = 0; k <= (j - i) / 2; k++)
                swap (a[i+k], a[j-k]);
        }
    cout << "0 0";

    return 0;
}





// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Jan 21, 2011 7:24:56 PM
// contest: 56
// link: /contest/56/submission/256939
// time: 1500 ms
// verdict: Accepted
// problem: 56B - Spoilt Permutation
// ID: 256939
// downloaded by very stupid script
