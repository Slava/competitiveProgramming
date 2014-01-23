// Kim Vyacheslav KarKTL
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    int n, flag;
    string s;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        flag  = 1;
        if (s.size() != 6){ flag = 0; goto end;}
        if (s[0] == 'A' || s[0] == 'B' || s[0] == 'C' || s[0] == 'E' || s[0] == 'H' || s[0] == 'K' ||
            s[0] == 'M' || s[0] == 'O' || s[0] == 'P' || s[0] == 'T' || s[0] == 'X' || s[0] == 'Y');
        else flag = 0;
        if (s[4] == 'A' || s[4] == 'B' || s[4] == 'C' || s[4] == 'E' || s[4] == 'H' || s[4] == 'K' ||
            s[4] == 'M' || s[4] == 'O' || s[4] == 'P' || s[4] == 'T' || s[4] == 'X' || s[4] == 'Y');
        else flag = 0;
        if (s[5] == 'A' || s[5] == 'B' || s[5] == 'C' || s[5] == 'E' || s[5] == 'H' || s[5] == 'K' ||
            s[5] == 'M' || s[5] == 'O' || s[5] == 'P' || s[5] == 'T' || s[5] == 'X' || s[5] == 'Y');
        else flag = 0;
        if (s[1] >= '0' && s[1] <= '9');
        else flag = 0;
        if (s[2] >= '0' && s[2] <= '9');
        else flag = 0;
        if (s[3] >= '0' && s[3] <= '9');
        else flag = 0;
end:        cout << (flag?"Yes":"No") << "\n";
    }

    return 0;
}

