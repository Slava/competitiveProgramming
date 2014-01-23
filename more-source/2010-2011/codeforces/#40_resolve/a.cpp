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
