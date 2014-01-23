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

int main ()
{
    char s, l;
    while (cin >> s)
        if ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z'))
            l = s;
    if (l >= 'A' && l <= 'Z')
        l = l - 'A' + 'a';
    switch (l)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'y':
            cout << "YES";break;
        default:
            cout << "NO";
    }

    return 0;
}

