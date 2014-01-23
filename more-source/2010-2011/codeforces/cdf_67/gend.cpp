// Kim Vyacheslav
// 2011
#include <cstdio>
#include <iostream>

#include <cmath>
#include <cstring>
#include <algorithm>

#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <utility>
#include <sstream>

using namespace std;

#define min(a,b) (a<b?a:b)
#define max(a,b) (a<b?b:a)
#define all(x) (x.begin(),x.end())
#define pb push_back
#define sqr(x) (x)*(x)

#define dbg(x) cout<<#x<<" = "<<x<<" "
#define forn(i,n) for(int i = 0; i < n; i++)
#define ford(i,n) for(int i = n - 1; i >= 0; i--)
const int inf = 1 << 30;

int main ()
{
        cout << "50 250000\n";
    for (int i = 0; i < 50; i++)
    {
        cout << "5000 ";
        for (int j = 0; j < 5000; j++){
            cout << ((rand() << 16) + rand())%1000;if( j != 4999)cout<<" ";}
        cout <<"\n";
    }
    for (int i = 0; i < 250000; i++){
        cout << rand() % 50 + 1 ;
        if(i!=250000-1)cout<< " ";else cout << "\n";
        }
    return 0;
}

