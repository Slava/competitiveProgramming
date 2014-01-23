#include <cstdio>
#include <vector>

using namespace std;

int n, a[20];
vector <int> s;

void r (int v)
{
    if (s.size() == n-v)
    {
        int Ss = s.size();
        for (int i = 0; i < Ss; i++)
        {
            if (s[Ss-i-1] == 1)
                a[v+i] = -1;
            else a[v+i] = -2;
        }
        for (int i = 0; i < n; i++)
            putchar ((a[i]==1?'(':a[i]==-1?')':a[i]==2?'[':']'));
        putchar('\n');

        return;
    }

    a[v] = 1;
    s.push_back(1);
    r(v+1);
    s.pop_back();

    if (!s.empty() && s.back() == 1)
    {
        a[v] = -1;
        s.pop_back();
        r(v+1);
        s.push_back(1);
    }

    a[v] = 2;
    s.push_back(2);
    r(v+1);
    s.pop_back();

    if (!s.empty() && s.back() == 2)
    {
        a[v] = -2;
        s.pop_back();
        r(v+1);
        s.push_back(2);
    }
}


int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%d", &n);
    r(0);

    return 0;
}

