// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    int a, b, c, r;
    char p;
    if (scanf("%d%c%d=%d", &a, &p, &b, &c) != 4 )
    {
        puts("ERROR");
        return 0;
    }
    if (p == '/' && !b)
    {
        puts("NO");
        return 0;
    }
    r = p == '+' ? a + b : p == '-' ? a - b : p == '*' ? a * b : a % c == 0 ? a / c : -c;
    puts(r == c ? "YES" : "NO");
    return 0;
}

