// Kim Vyacheslav KarKTL
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char q[1009], s[1009], o[6] = {'(', '[', '{', ')', ']', '}'}, e[1009];
int i, j, k, l, r, t[1009], u, p;
bool d() {
    for (j = r = 0; j < l; j++) {
        for (k = u = 0; k < 3; k++)
            if (s[j] == o[k]) {
                u = 1;
                break;
            }
        if (u == 1) {
            r++;
            e[r] = s[j];
            t[r] = k;
        }
        else {
            if (r > 0) {
                for (k = 3; k < 6; k++)
                    if (s[j] == o[k])
                        break;
                if (t[r] + 3 == k)
                    r--;
                else
                    return 0;
            }
            else
                return 0;
        }
    }
    if (r > 0)
        return 0;
    else
        return 1;
}
int main ()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    cin >> q;
    l = strlen(q);
    for (i = 0; i < l; i++) {
        for (j = i, k = 0; k < l; k++, j = (j + 1) % l)
            s[k] = q[j];
        if (d()) p = 1;
    }
    if (p == 1) cout << "YES";
    else cout << "NO";

}
