// Kim Vyacheslav KarKTL
#include <cstdio>
#include <set>
#include <string>
#include <iostream>

using namespace std;

int main ()
{
    set <pair <string, string> > s;
    int n;
    string a, b;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        s.insert (make_pair(a, b));
    }

    printf ("%d", s.size());

    return 0;
}




// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Dec 1, 2010 7:05:40 AM
// contest: 44
// link: /contest/44/submission/185824
// time: 30 ms
// verdict: Accepted
// problem: 44A - Indian Summer
// ID: 185824
// downloaded by very stupid script
