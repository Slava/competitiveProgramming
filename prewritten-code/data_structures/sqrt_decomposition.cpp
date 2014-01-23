// Kim Vyacheslav
// sum on range [a,b]
// build - O(n)
// find - O(sqrtn)
#include <cstdio>
#include <cmath>

using namespace std;

int main ()
{
    int n, a[2000], b[50] = {0}, bl;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d", &a[i]);
// precalc
    bl = sqrt(n + .0) + 1;
    for (int i = 0, pos = 0, block = 0; i < n; i++)
    {
        b[block] += a[i];
        pos++;
        if (pos == bl)
        {
            block++;
            pos = 0;
        }
    }
// find sum
    for (int l, r, sum = 0;; sum = 0)
    {
        scanf ("%d%d", &l, &r);
        for (int i = l, block = l/bl, pos = l%bl;
                                        i <= r;)
            if (pos == 0 && i + bl - 1 <= r)
            {
                sum += b[block];
                block++;
                i += bl;
                pos = 0;
            }
            else
            {
                sum += a[i];
                i++;
                if (pos == bl)
                {
                    pos = 0;
                    block++;
                }
        }
        printf ("%d\n", sum);
    }

    return 0;
}

