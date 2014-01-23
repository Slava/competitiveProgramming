// Kim Vyacheslav KarKTL
#include <cstdio>
#include <vector>

using namespace std;

char a[9];
int m, n;

int p (int i, int j)
{
    if (j-i+1 == 2)
        return a[i] == a[j] ? 2 : 0;
    if (j-i+1 == 3)
        return a[i] == a[i+1] && a[i] == a[i+2] ? 3 :
                a[i] == a[i+1] ? 2 :
                a[i] == a[i+2] ? 2 :
                a[i+1] == a[i+2] ? 2 : 0;
    if (j-i+1 == 4)
        return a[i] == a[i+1] && a[i] == a[i+2] && a[i] == a[i+3] ? 5 :
                a[i] == a[i+3] && a[i+1] == a[i+2] ? 4 :
                a[i] == a[i+1] && a[i+2] == a[i+3] ? 3 :
                a[i] == a[i+2] && a[i+1] == a[i+3] ? 3 :
                a[i] == a[i+1] && a[i] == a[i+2] ? 3 :
                a[i] == a[i+2] && a[i] == a[i+3] ? 3 :
                a[i+1] == a[i+2] && a[i+2] == a[i+3] ? 3 :
                a[i+1] == a[i+3] || a[i] == a[i+2] ? 2 : 0;
}

int main ()
{
   freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%s", a);
    m = p (0,3) + p (4,6);
    n = 1;
    int t = p (0,2) + p (3,6);
    if (t > m)
    {
        m = t;
        n = 2;
    }
    t = p(0,2) + p(3,4) + p(5,6);
    if (t > m)
    {
        m = t;
        n = 3;
    }
    t = p(0,1) + p(2,3) + p(4,6);
    if (t > m)
    {
        m = t;
        n = 4;
    }
    t = p(0,1) + p(2,4) + p(5,6);
    if (t > m)
    {
        m = t;
        n = 5;
    }

    switch (n)
    {
        case 1:
            printf("%c%c%c%c-%c%c%c\n", a[0],a[1],a[2],a[3],a[4],a[5],a[6]);
            break;
        case 2:
            printf("%c%c%c-%c%c%c%c\n", a[0],a[1],a[2],a[3],a[4],a[5],a[6]);
            break;
        case 3:
            printf("%c%c%c-%c%c-%c%c\n", a[0],a[1],a[2],a[3],a[4],a[5],a[6]);
            break;
        case 4:
            printf("%c%c-%c%c-%c%c%c\n", a[0],a[1],a[2],a[3],a[4],a[5],a[6]);
            break;
        case 5:
            printf("%c%c-%c%c%c-%c%c\n", a[0],a[1],a[2],a[3],a[4],a[5],a[6]);
    }
    printf("%d", m);
    return 0;
}
