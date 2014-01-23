#include <iostream>

using namespace std;

char s[20];
int n, a[27], i;
long long r;

long long f(int n)
{
    long long r = 1;
    int i = 2;
    for(;i <= n; i++)
        r *= i;
    return r;
}

int main ()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    gets(s);
    n = strlen(s);
    r = f(n);
    for(i = 0; i < n; i++)
        a[s[i] - 'a']++;
    for(i = 0; i < 27; i++)
        if(a[i])r /= f(a[i]);

    cout << r;

    return 0;
}

