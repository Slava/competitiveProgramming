#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main ()
{
    string a = "hello";
    string s;
    bool N = 1;
    int i, j;
    i = j = 0;
    cin >> s;
    if (s.size() < 5)
    {
            cout << "NO";
            return 0;
    }
    for (i = j = 0;i < a.size() && j < s.size();)
    {
        if (s[j++] == a[i])
            i++;
    }
    if (i != a.size())
        cout<<"NO";
    else cout << "YES";
    return 0;
}




// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Jan 31, 2011 7:12:35 PM
// contest: 58
// link: /contest/58/submission/268923
// time: 30 ms
// verdict: Accepted
// problem: 58A - Chat room
// ID: 268923
// downloaded by very stupid script
