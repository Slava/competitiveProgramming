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





// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Mar 7, 2011 3:17:54 PM
// contest: 65
// link: /contest/65/submission/323400
// time: 30 ms
// verdict: Accepted
// problem: 65A - Harry Potter and Three Spells
// ID: 323400
// downloaded by very stupid script
