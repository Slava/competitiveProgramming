// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int a[500][500], bitmap[500][500], x, y, c;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    string s;
    cin >> s;

    a[250][250] = 1;
    x = y = 250;
    for (int i = 0; i < s.size(); i++)
    {
        c = a[x][y];
        switch (s[i])
        {
            case 'N':
                y++;
                bitmap[x][y] |= 2;
                break;
            case 'S':
                y--;
                bitmap[x][y] |= 1;
                break;
            case 'W':
                x++;
                bitmap[x][y] |= 8;
                break;
            case 'E':
                x--;
                bitmap[x][y] |= 4;
                break;
        }
        a[x][y] = c + 1;
    }

    while (x != 250 || y != 250)
    {
        int minpath = 7777777, d = 0;
        if (bitmap[x][y] & 1)
            if (a[x][y + 1] < minpath)
            {
                d = 1;
                minpath = a[x][y + 1];
            }
        if (bitmap[x][y] & 2)
            if (a[x][y - 1] < minpath)
            {
                d = 2;
                minpath = a[x][y - 1];
            }
        if (bitmap[x][y] & 4)
            if (a[x + 1][y] < minpath)
            {
                d = 4;
                minpath = a[x + 1][y];
            }
        if (bitmap[x][y] & 8)
            if (a[x - 1][y] < minpath)
            {
                d = 8;
                minpath = a[x - 1][y];
            }
        switch (d)
        {
            case 1:
                y++;cout << "N";break;
            case 2:
                y--;cout << "S";break;
            case 4:
                x++;cout << "W";break;
            case 8:
                x--;cout << "E";break;
        }
    }

    return 0;
}

