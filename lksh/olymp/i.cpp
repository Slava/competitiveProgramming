#include <cstdio>
#include <string>
#include <iostream>

#include <cstring>
using namespace std;

const int N = 256;
int a[N][N], n, flag;
string s;

int solve()
{
    //     cin >> s;
    memset(a, 0, sizeof a);
    if (s[0] != '-')
        s = "+" + s;
    n = (int)s.size();
    for (int i = 0; i < n; i += 3)
    {
        if (s[i] == '-')
            flag = 1;
        else flag = 0;
        int A = s[i + 1], B = s[i + 2];
        if (flag) swap(A, B);
        a[A][B]++;
    }
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                int mn = min(a[i][k], a[k][j]);
                a[i][k] -= mn;
                a[k][j] -= mn;
                a[i][j] += mn;
            }
    int fff=0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            while (a[i][j]--)
            {
                if (fff)printf("+");
                fff=1;
                printf("%c%c", i, j);

            }
    if (!fff)printf("0");
    printf("\n");
    return 0;
}
int main()
{
    while(cin >> s)
        solve();
    return 0;
}
