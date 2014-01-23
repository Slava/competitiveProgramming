#include <cstdio>

using namespace std;

#define b(i) (b.e(i))
#define max(a,b) (a>b?a:b)
#define LEN 10000

class L
{
friend void set (L&, int);
private:
    short a[LEN];
    int SIZE;
public:
    L()
    {
        for (int i = 0; i < LEN; i++)
            a[i] = 0;
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
            printf("%d", a[i]);
	puts ("");
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

    void operator *= (L &b)
    {
        int z[LEN + 9], i, j, c = 0;
        for (i = 0; i < SIZE; i++)
        {
            c = 0;
            for (j = 0; j < b.size(); j++)
            {
                z[i + j] += c + a[i] * b(j);
                c = z[i + j] / 10;
                z[i + j] %= 10;
            }
            z[i + j] = c;
        }
        for (int i = 0; i < LEN; i++)
            a[i] = z[i];
        SIZE += b.size();
        while (a[SIZE]) SIZE++;
        while (SIZE > 1 &&!a[SIZE - 1]) SIZE--;
    }
    void zero ()
    {
        for (int i = 0; i <= SIZE; i++)
            a[i] = 0;
        SIZE = 1;
    }
}a[4], t;

void set (L &a, int x)
{
    a.a[0] = x;
    a.SIZE = 1;
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    int n;
    scanf ("%d", &n);
    set (a[0], 1);
    set (a[1], 2);

    for (int i = 2; i < n; i++)
        {a[i%4] = a[(i - 1)%4]; a[i%4] += a[(i - 2)%4];}
    t = a[(n - 1)%4];
    a[(n - 1)%4] *= t;
    a[(n - 1)%4].print();

    return 0;
}
