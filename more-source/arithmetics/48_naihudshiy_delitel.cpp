// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#include <cstring>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    char s[6000];
    int a = 0;
    gets (s);
    for (int i = strlen(s) - 1; i; i--)
        if (s[i] == 48)
            a++;
    printf ("1");
    for (int i = 0; i < a; i++)
        printf ("0");
    return 0;
}

