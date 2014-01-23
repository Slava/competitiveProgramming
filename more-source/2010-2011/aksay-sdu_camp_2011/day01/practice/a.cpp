#include <cstdio>
#include <cstring>

using namespace std;

int main ()
{
    char s[300000];
    int  z[300000], l, r, i, j, len;
    z[0] = l = r = 0;
    scanf ("%d%s", &len, s);

    for (i = 1; i < len; i++)
        if (i > r)
        {
            for (j = 0; i + j < len && s[i + j] == s[j]; j++);
            z[i] = j;
            l = i;
            r = r + j - 1;
        }
        else
            if (z[i - l] < r - i + 1)
                z[i] = z[i - l];
            else
            {
                for (j = 1; r + j < len && s[r + j] == s[r - i + j]; j++);
                z[i] = r - i + j;
                l = i;
                r = r + j - 1;
            }
    for (i = 0; i < len; i++)
        printf ("%d ", z[i]);

    return 0;
}

