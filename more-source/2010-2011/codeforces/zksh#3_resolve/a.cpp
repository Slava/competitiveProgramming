// Kim Vyacheslav KarKTL
#include <cstdio>
#include <cstring>

using namespace std;

char *s[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
char i[20];
int n;

int main ()
{
    scanf ("%s %d", i, &n);
    for (int j = 0; j < 12; j++)
        if (strcmp(s[j], i) == 0)
            printf ("%s", s[(j + n)%12]);


    return 0;
}
