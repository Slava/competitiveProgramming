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
#define f first
#define s second

// r 0
// s 1
// p 2
int b[3][3];
int main ()
{
    pair<int, char> A[3];
    string a;
    b[0][1] = 1;
    b[1][2] = 1;
    b[2][0] = 1;
    for (int i = 0; i < 3; i++)
    {
        cin >> a;
        if (a[0] == 'r')A[i].f = 0;
        if (a[0] == 's')A[i].f = 1;
        if (a[0] == 'p')A[i].f = 2;
    }
    A[0].s = 'F';
    A[1].s = 'M';
    A[2].s = 'S';

    for (int i = 0; i < 3; i++)
    {
        if (b[A[i].f][A[(i + 1) % 3].f] && b[A[i].f][A[(i + 2) % 3].f]){
            printf ("%c", A[i].s);
            return 0;
        }
    }
    puts("?");
    return 0;
}





// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Dec 12, 2010 12:13:32 PM
// contest: 48
// link: /contest/48/submission/218075
// time: 30 ms
// verdict: Accepted
// problem: 48A - Rock-paper-scissors
// ID: 218075
// downloaded by very stupid script
