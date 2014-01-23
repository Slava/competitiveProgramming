// Kim Vyacheslav
// 2011
#include <cstdio>
#include <iostream>

#include <cmath>
#include <cstring>
#include <algorithm>

#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <utility>
#include <sstream>

using namespace std;

#define min(a,b) (a<b?a:b)
#define max(a,b) (a<b?b:a)
#define all(x) (x.begin(),x.end())
#define pb push_back
#define sqr(x) (x)*(x)

#define dbg(x) cout<<#x<<" = "<<x<<" "
#define forn(i,n) for(int i = 0; i < n; i++)
#define ford(i,n) for(int i = n - 1; i >= 0; i--)
const int inf = 1 << 30;

long n,primes[200]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107 ,109 ,113 ,127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211 ,223, 227, 229 ,233};

#define b(i) (b.e(i))

class L
{
private:
    short a[1000000];
    int SIZE;
public:
    L()
    {
        for (int i = 0; i < 1000000; i++)
            a[i] = 0;
        a[0] = 1;
        SIZE = 1;
    }
    int size ()
    {
        return SIZE;
    }
    int e (int i)
    {
        return a[i];
    }
    void print ()
    {
        for (int i = SIZE - 1; i >= 0; i--)
            printf("%d", a[i]);puts("");
    }
    void operator += (L &b)
    {
        SIZE = max(SIZE, b.size());
        int c = 0;
        for (int i = 0; i < SIZE; i++)
        {
            c = a[i] + b(i) + c;
            a[i] = c%10;
            c /= 10;
        }
        if (c)
        {
            a[SIZE++] = c;
            c = 0;
        }
    }
    void operator -= (L &b)
    {
        for (int i = 0; i < SIZE; i++)
        {
            a[i] -= b(i);
            if (a[i] < 0)
            {
                a[i] += 10;
                a[i+1]--;
            }
        }
        while (!a[SIZE - 1] && SIZE > 1) SIZE--;
    }
    void operator *= (long b)
    {
        int c = 0;
        for (int i = 0; i < SIZE; i++)
        {
            c = c + a[i] * b;
            a[i] = c%10;
            c /= 10;
        }
        while (c)
        {
            a[SIZE++] = c%10;
            c /= 10;
        }
    }
    void operator /= (long b)
    {
        int c = 0;
        for (int i = SIZE - 1; i >= 0; i--)
        {
            a[i] += c;
            c = a[i] - (a[i] / b) * b;
            a[i] /= b;
            c *= 10;
        }
        while (!a[SIZE-1] && SIZE > 1)
            SIZE--;
    }
    void operator *= (L &b)
    {
        long c = 0;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < b.size(); j++)
            {
                c = a[i] * b(i) + c;
                a[i] = c%10;
                c /= 10;
            }
        }

        SIZE = SIZE + b.size();
        while (c)
        {
            a[SIZE++] = c%10;
            c /= 10;
        }
    }
}a[100];
int main ()
{
    scanf ("%d", &n);
    if (n == 2){
        cout << "-1";
return 0;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (j != i)
                a[j] *= primes[i];
    for (int i = 0; i < n; i++)
        a[i].print();
    return 0;
}

