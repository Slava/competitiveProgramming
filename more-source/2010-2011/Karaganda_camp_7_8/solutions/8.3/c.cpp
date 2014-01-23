// Sitmuhambetov Satjan
#include <iostream>
#include <string>

using namespace std;
string s;
int l, a[19], u[19], b[19];
void d(int k) {
    int i;
    if (k < l) {
        for (i = 0; i < l; i++) {
            if (u[i] == 0) {
                u[i] = 1;
                b[k] = a[i];
                d(k + 1);
                u[i] = 0;
                b[k] = 0;
            }
        }
    }
    else {
        for (i = 0; i < l; i++)
            cout <<(char)b[i];
        cout << "\n";
    }
}
int main () {
    cin >> s;
    int i;
    l = s.length();
    for (i = 0; i < l; i++)
        a[i] = s[i];
    sort(a, a + l);
    d(0);
}

