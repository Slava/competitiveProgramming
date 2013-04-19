// Kim Vyacheslav KarKTL
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main ()
{
    string a, b;
    cin >> a >> b;
    if (a.size() != b.size())
    {
        puts("NO");
        return 0;
    }
    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[b.size() - i - 1])
        {
            puts("NO");
            return 0;
        }
    puts ("YES");
    return 0;
}




// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Nov 25, 2010 9:58:25 AM
// contest: 41
// link: /contest/41/submission/190600
// time: 30 ms
// verdict: Accepted
// problem: 41A - Translation
// ID: 190600
// downloaded by very stupid script
