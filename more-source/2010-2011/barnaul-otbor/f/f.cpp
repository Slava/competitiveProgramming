#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector <int> ans;

int main ()
{
    freopen ("safe.in","r",stdin);
    freopen ("safe.out","w",stdout);


    char s[12];
    bool z = 0, p = 0;
    int a[12], zeros = 0;
    gets (s);
    int n = strlen (s), halfn = (n-1)/2;

    for (int i = 0; i < n; i++)
        a[i] = s[i] - '0';

    if(n%2==0)
    {
        for (int i = halfn; i >= 0; i--)
        {
            if (p)
            {
                ans.push_back(a[i]);
                continue;
            }
            if (a[i] == a[n-1-i])
            {
                ans.push_back(a[i]);
                continue;
            }
            if (a[i] < a[n-1-i])
            {
                if (!z)
                {
                    zeros += ans.size();
                    ans.clear();
                    ans.push_back(a[i]+1);
                    z=1;
                }
                else
                {
                    ans.push_back(a[i]);
                }
                continue;
            }
            if (a[i] > a[n-1-i])
            {
                ans.push_back(a[i]);
                p=1;
            }
        }
        for (int i = ans.size() -1; i >= 0; i--)
            printf ("%d", ans[i]);
        for (int i = 0; i < zeros*2; i++)
            putchar('0');
        for (int i = 0; i < ans.size(); i++)
            printf ("%d", ans[i]);
    }

    else
    {
        bool I = 0;
        for (int i = 0; i < halfn; i++)
        {
            if (a[i] > a[n-i-1])a[n-i-1] = a[i];
        }
        for (int i = 0; i < n; i++)
            if (a[i]!=a[n-1-i])I = 1;
        if (I)
        {
            for (int i = 0; i <= halfn; i++)
            {
                a[halfn-i]++;
                if (a[halfn-i] < 10)break;
                a[halfn-i] = 0;
            }
            for (int i = halfn + 1; i < n; i++)
                a[i] = a[n-i-1];
        }
        for (int i = 0; i < n; i++)
            printf ("%d", a[i]);
    }

    return 0;
}
