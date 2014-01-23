#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream fin("A.in");
ofstream fout("A.out");
long long k, m, a[10009], l, x, b;
string s;
int main () {
    fin >> k >> m >> s;
    l = s.length();
    a[l - 1] = 1 % m;
    for (int i = l - 2; i >= 0; i--) a[i] = ( a[i + 1] * k ) % m;
    for (int i = 0; i < l; i++) {
        if (s[i] <= '9' && s[i] >= '0') x = s[i] - '0';
        if (s[i] >= 'A' && s[i] <= 'Z') x = s[i] - 'A' + 10;
        b = (b + x * a[i]) % m;
    }
    fout << b;
}
