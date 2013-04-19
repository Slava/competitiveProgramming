#include <cstdio>

inline void swap (int &A, int &B)
{
    int t = A;
    A = B;
    B = t;
}

inline int max(int a, int b)
{
    return a > b ? a : b;
}

const int N = 1010101;
int n, k, a[N], b[N], pos[N], u[N], i, P;

int main ()
{
    scanf ("%d", &n);
    for (i = 0; i < 3 * n; i++)
    {
        scanf ("%d", &k);
        a[--k] = i;
    }
    for (i = 0; i < n; i++){
        for (int j = 0; j < 3; j++)
            scanf ("%d", b + i * 3 + j),
            b[i*3+j]--;
        if (a[b[i*3]] > a[b[i*3+1]])
            swap(b[i*3], b[i*3+1]);
        if (a[b[i*3]] > a[b[i*3+2]])
            swap(b[i*3], b[i*3+2]);
        for (int j = 0; j < 3; j++)
            pos[b[i*3+j]] = i*3+j;
    }
    scanf ("%d", &k);k--;
    if (pos[k] % 3 != 0)
    {
        for (i = 0; i < 3 * n; i++)
            if (i != k) printf("%d ", i + 1);
    }
    else 
    {
        for (i = 0; i < 3 * n; i++)
            if (b[i] == k)
                break;
            else u[b[i]] = 1;
        u[b[i + 1]] = u[b[i + 2]] = 2;
        P = max(b[i + 1], b[i + 2]);
        for (i = 0; i < 3 * n; i++)
            if ((u[i] == 2 || (u[i] == 1 && P > i))
                && i != k)
                printf("%d ", i + 1);
        for (i = 0; i < 3 * n; i++)
            if ((!u[i] || (u[i] == 1 && P < i)) && i != k)
                printf("%d ", i + 1);
    }
    return 0;
}




// lang: GNU C++
// memory: 17100 KB
// author: imslavko
// submit_date: Mar 2, 2011 9:18:13 AM
// contest: 59
// link: /contest/59/submission/313891
// time: 330 ms
// verdict: Accepted
// problem: 59D - Team Arrangement
// ID: 313891
// downloaded by very stupid script
