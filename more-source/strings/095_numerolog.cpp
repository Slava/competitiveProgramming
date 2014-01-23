// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#include <string>

using namespace std;


char st[2000];
int i, ans;
string s, t;

void sum(int b)
{
    for(int j = 0; b || j < t.size(); j++)
    {
        if (j == t.size())
            t.push_back(0);
        t[j] += b;
        b = t[j] / 10;
        t[j] %= 10;
    }
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%s", st);
    s = st;
    for (i = 0; i < s.size(); i++)
        s[i] -= '0';
    for (;s.size() > 1; ans++)
    {
        t.clear();
        t.push_back(0);
        for(i = 0; i < s.size(); i++)
            sum(s[i]);
        s = t;
    }

    printf("%d %d", s[0], ans);

    return 0;
}

