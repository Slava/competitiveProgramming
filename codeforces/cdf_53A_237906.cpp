#include <string>
#include <iostream>
#include <set>

using namespace std;

set <string> occur;
string s, a;
int n;

int main ()
{
    cin >> s >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a.size() >= s.size() && a.substr(0, s.size()) == s)
            occur.insert(a);
    }
    if (!occur.size())
        cout << s;
    else cout << (*occur.begin());

    return 0;
}





// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Jan 6, 2011 7:05:38 PM
// contest: 53
// link: /contest/53/submission/237906
// time: 30 ms
// verdict: Accepted
// problem: 53A - Autocomplete
// ID: 237906
// downloaded by very stupid script
