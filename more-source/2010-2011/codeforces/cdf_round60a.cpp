#include <cstdio>

int main ()
{
    int a, b, c, d, e, f;
    scanf ("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    int ace = a * c * e,
           bdf = b * d * f;
    if (!ace && ! bdf)
        if ((!c&&d) || (!a&&b&&d) || (!e&&f&&b&&d))
            puts ("Ron");
        else puts("Hermione");
    else if (ace >= bdf)
        puts("Hermione");
    else puts("Ron");
    return 0;
}

