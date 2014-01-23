// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#include <algorithm>

using namespace std;

int a[4], b[4], i;
bool check ()
{
    return a[0] == 6 && a[1] == 1 && a[2] == 7 && a[3] == 4;
}

void k ()
{
    int carry = 0;
    for (int i = 0; i < 4; i++)
        b[i] = a[i];
    sort (b, b + 4);
    for (int i = 3; i >= 0; i--)
    {
        a[i] = b[3 - i] - b[i] - carry;
        if (a[i] < 0)
        {
            a[i] += 10;
            carry = 1;
        }
        else carry = 0;
    }
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    char s[5];
    scanf ("%s", s);
    a[0] = s[0] - '0';
    a[1] = s[1] - '0';
    a[2] = s[2] - '0';
    a[3] = s[3] - '0';
    for (;!check(); i++)
        k ();
    printf ("6174\n%d", i);

    return 0;
}

