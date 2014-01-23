#include <iostream>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    int n, l, k, a[120][120], i, j, p, d[101], c = 100000;
    cin >> n;

    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            cin >> a[i][j];

    for(l = 1; l <= n; l++)
    {
        for(i = 1; i <= n; i++)d[i] = c;
        d[l] = 0;
        for(k = 1; k <= n; k++)
        {
            p = 0;
            for(i = 1; i <= n; i++)
                for(j = 1; j <= n; j++)
                    if(a[i][j] != c && d[j] > d[i] + a[i][j])
                    {
                        d[j] = d[i] + a[i][j];
                        p = 1;
                    }

            if (!p)break;
        }
        if (p)break;
    }
    if (p)
        cout<<"YES";
    else
        cout<<"NO";
}
