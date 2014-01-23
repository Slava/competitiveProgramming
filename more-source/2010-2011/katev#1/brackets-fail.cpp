// Slava Kim 10b KarKTL
//German, privet
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int actualn, n;
string  t, b;
set <string>a;

void make (int l, int r)
{
    if (l > r)
    {
        b.clear();
        for (int i = 0; i < actualn;i++)
            if (!t[i])b = (t[actualn-i-1]==')')?b + "(":b + "[";
            else b = b+t[i];
        a.insert(b);
        return;
    }
    t[l] = '(';
    t[r] = ')';
    make (l+1, r-1);

    t[l] = '[';
    t[r] = ']';
    make (l+1, r-1);
if (r-l > 0){
    t[l] = '(';
    t[l+1] = ')';
    make(l+2, r);

    t[l] = '[';
    t[l+1] = ']';
    make(l+2, r);
    t[r-1] = '(';
    t[r] = ')';
    make(l, r-2);

    t[r-1] = '[';
    t[r] = ']';
    make(l, r-2);
}

}

int main ()
{
    freopen ("brackets.in", "r", stdin);
    freopen ("brackets.out", "w", stdout);

    scanf("%d", &actualn);
    t = "";
    if (actualn%2 == 1)
        return 0;
    make(0, actualn-1);
    n = a.size();
    for (set<string>::iterator i = a.begin();
            i != a.end(); ++i)
            cout << *i << "\n";

    return 0;
}

