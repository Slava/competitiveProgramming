#include <iostream>
#include <string>

using namespace std;
#define swap(x, y) {int t = x; x = y; y = t;}
int i, n, d[9];
class times {
public:
    string s;
    int c[99], i, l, j;
    bool V(char q) {
        return (q >= '0' && q <= '9');
    }
    void make() {
        for (i = 0; i < 4; i++)
            c[i] = 0;
        l = s.length();
        for (i = 0, j = 1; i < l; i++, j++) {
            for (; V(s[i]); i++)
                c[j] = c[j] * 10 + (s[i] - 48);
        }
        j--;
        for (i = 3; i > (3 - j); i--)
            swap(c[i] , c[i - (3 - j)]);
    }
};
int main () {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    times a, b;
    cin >> a.s >> b.s;
    a.make(); b.make();
    for (i = 1; i < 4; i++)
        d[i] = a.c[i] + b.c[i];
    d[2] += d[3] / 60;
    d[3] %= 60;
    d[1] += d[2] / 60;
    d[2] %= 60;
    n = d[1] / 24;
    d[1] %= 24;
    if (d[1] < 10) printf("0");
    cout << d[1] << ":";
    if (d[2] < 10) printf("0");
    printf("%d:", d[2]);
    if (d[3] < 10) printf("0");
    cout << d[3];
    if (n > 0) printf("+%d days", n);
}

 
 