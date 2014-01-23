#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

char s[200000];
int x = 0;

main ()
{
    freopen ("auxiliary.in", "r", stdin);
    freopen ("auxiliary.out", "w", stdout);

    gets(s);
    int n = strlen(s), j;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ')')
        {
          if (x <= 0){
            n++;
                for (j = i-1; j>=0;j--)
                    if (s[j] == ')')break;
            j++;
            for (int k = n-1; k > j; k--)
                s[k] = s[k-1];
            s[j] = '(';
            i++;goto NE;
          }
          else x--;
        }
        if (s[i] == '(')
            x++;
    NE:;
    }
    for (int i = 0; i < x; i++)
        s[n+i] = ')';
    n+=x;

    if (s[0] == '+')
    {
        n++;
        for (int k = n-1; k > 0; k--)
            s[k] = s[k-1];
        s[0] = '0';
    }
    for (int i = 0; i < n-1; i++)
    {
        if (s[i] == '+' && s[i+1] == '+')
        {
            n++;
            for (int k = n-1; k > i+1; k--)
                s[k] = s[k-1];
            s[++i] = '0';
        }
    }

    if (s[n-1] == '+')
        s[n++] = '0';

    for (int i = 0; i < n; i++)
    {
        cout << s[i];
        if (i!= n-1 && s[i] == ')' && s[i+1] == '(')cout << "+";
        if (i!= n-1 && s[i] == '(' && s[i+1] == ')')cout << "0";
        if (i!= n-1 && s[i] == '(' && s[i+1] == '+')cout << "0";
        if (i!= n-1 && s[i] == '+' && s[i+1] == ')')cout << "0";
    }
    return 0;
}

