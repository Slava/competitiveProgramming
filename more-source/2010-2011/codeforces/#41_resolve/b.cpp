// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>

using namespace std;

int l1x, l1y, l2x, l2y, wkx, wky, bkx, bky;
bool a[10][10], b[10][10];
char s[3];
int k[] = {0, 1, 1, 0, 0, -1, -1, 0, 1, 1, -1, -1, 1, -1, -1, 1};

int main ()
{
    scanf ("%s", s);
    l1x = s[0] - 'a' + 1;
    l1y = s[1] - '0';
    scanf ("%s", s);
    l2x = s[0] - 'a' + 1;
    l2y = s[1] - '0';
    scanf ("%s", s);
    wkx = s[0] - 'a' + 1;
    wky = s[1] - '0';
    scanf ("%s", s);
    bkx = s[0] - 'a' + 1;
    bky = s[1] - '0';

    for (int i = l1x; i <= 8; i++)
        if (i == wkx && l1y == wky)break;
        else a[i][l1y] = 1;
    for (int i = l1x; i > 0; i--)
        if (i == wkx && l1y == wky)break;
        else a[i][l1y] = 1;
    for (int i = l2x; i <= 8; i++)
        if (i == wkx && l2y == wky)break;
        else a[i][l2y] = 1;
    for (int i = l2x; i > 0; i--)
        if (i == wkx && l2y == wky)break;
        else a[i][l2y] = 1;

    for (int i = l1y; i <= 8; i++)
        if (l1x == wkx && i == wky)break;
        else a[l1x][i] = 1;
    for (int i = l1y; i > 0; i--)
        if (l1x == wkx && i == wky)break;
        else a[l1x][i] = 1;
    for (int i = l2y; i <= 8; i++)
        if (l2x == wkx && i == wky)break;
        else a[l2x][i] = 1;
    for (int i = l2y; i > 0; i--)
        if (l2x == wkx && i == wky)break;
        else a[l2x][i] = 1;


    for (int i = 0; i < 16; i++)
        a[wkx + k[i]][wky + k[i + 1]] = b[wkx + k[i]][wky + k[i + 1]] = 1;

    if (!a[bkx][bky])
    {
        puts ("OTHER");
        return 0;
    }

    for (int i = 0; i < 16; i++)
    {
        if (!(bkx + k[i] > 0 && bkx + k[i] < 9 && bky + k[i + 1] > 0 && bky + k[i + 1] < 9))
            continue;
        if (!a[bkx + k[i]][bky + k[i + 1]])
        {
            puts ("OTHER");
            return 0;
        }
        if (((bkx + k[i] == l1x && bky + k[i + 1] == l1y) || (bkx + k[i] == l2x && bky + k[i + 1] == l2y)) && l1x != l2x && l1y != l2y && !b[bkx + k[i]][bky + k[i + 1]])
        {
            puts ("OTHER");
            return 0;
        }
    }

    puts ("CHECKMATE");

    return 0;
}
