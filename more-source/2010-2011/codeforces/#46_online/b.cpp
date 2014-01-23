// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <string>
#include <cstring>


using namespace std;

int a, b, m = 0, M = 0, c;
int C[10], size;

int p (int k)
{
    size = 0;
    int carry = 0;
    int t1 = a, t2 = b;
    for (; carry || t1 || t2; t1 /= 10, t2 /= 10)
    {
        C[size] = carry + (t1%10) + (t2%10);
        carry = C[size] / k;
        C[size] %= k;
        size++;
    }
    return size;
}

int main ()
{
    cin >> a >> b;
    c = a + b;

    for (int t = a; t; t /= 10)
        m = max (m, t % 10);
    for (int t = b; t; t /= 10)
        m = max (m, t % 10);
    for (int i = 36; i > m; i--)
        M = max (M, p(i));
    if (!M) M = 1;
    cout << M;
    return 0;
}

