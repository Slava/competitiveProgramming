// Kim Vyacheslav KarKTL
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> m;
int n, t, flag, flag2;

int main ()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &t);
        if (t > 0) {printf ("%d ", t); flag = 1;}
        if (t < 0) m.push_back(t);
        if (!t) flag2 = 1;
    }
    sort (m.begin(), m.end());
    if (m.size())
    for (int i = 0; i < (m.size() - 1); i += 2)
        printf ("%d %d ", m[i], m[i + 1]);
    if (!flag)
    {
        if (m.size() == 1)
        {
            if (flag2)  printf("0");
            else printf ("%d", m[0]);
        }
        if (m.size() == 0 && flag2)
            printf ("0");
    }
    return 0;
}

