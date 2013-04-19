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




// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Nov 23, 2010 1:51:32 PM
// contest: 45
// link: /contest/45/submission/196109
// time: 10 ms
// verdict: Accepted
// problem: 45A - Codecraft III
// ID: 196109
// downloaded by very stupid script
