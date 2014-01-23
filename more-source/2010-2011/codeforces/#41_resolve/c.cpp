// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>

using namespace std;

int a[5];
int main ()
{
    scanf ("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
    while (a[0]!=1||a[1]!=1||a[2]!=1||a[3]!=1)
    {
        bool f = 1;
        for (int i = 0; i < 4; i++)
            if (a[i]%2 == 0 && a[(i + 1) % 4]%2 == 0)
            {
                printf ("/%d\n", i + 1);
                a[i] >>= 1;
                a[(i + 1) % 4] >>= 1;
                f = 0;
                break;
            }
        if (f)
        {
            for (int i = 0; i < 4; i++)
                if (a[i]%2 == 1 && a[(i + 1)%4]%2 == 1 && !(a[i] == 1 && a[(i + 1)%4] == 1))
                {
                    a[i]++;
                    a[(i + 1)%4]++;
                    printf ("+%d\n", i + 1);
                    f = 0;
                    break;
                }
            if (f)
            for (int i = 0; i < 4; i++)
                if (a[i]%2 == 1 && a[(i + 1)%4]%2 == 0 && a[(i + 2)%4]%2 == 1)
                {
                    printf ("+%d\n+%d\n", i + 1, (i + 1)%4 + 1);
                    a[i]++;
                    a[(i + 2)%4]++;
                    a[(i + 1)%4] += 2;
                    break;
                }
        }
    }

    return 0;
}
