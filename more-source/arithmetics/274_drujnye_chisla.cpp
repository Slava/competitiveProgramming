// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    int n;
    char s[15];
    scanf ("%d", &n);
    set <char> a, b;
    for (int i = 0; i < n; i++)
    {
        a.clear();b.clear();
        scanf ("%s", s);
        for (int j = 0; j < strlen(s); j++)
            a.insert(s[j]);
        scanf ("%s", s);
        for (int j = 0; j < strlen(s); j++)
            b.insert(s[j]);

        puts(a == b?"YES":"NO");
    }

    return 0;
}

