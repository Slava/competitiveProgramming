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

