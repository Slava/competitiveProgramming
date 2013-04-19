// Kim Vyacheslav KarKTL
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int A[300], B[300];

int main ()
{
//    freopen ("input.txt", "r", stdin);
//    freopen ("output.txt", "w", stdout);

    string a, b;
    getline(cin, a);
    getline(cin, b);

    for (int i = 0; i < a.size(); i++)
        A[a[i]]++;
    for (int i = 0; i < b.size(); i++)
        B[b[i]]++;
    A[' '] = B[' '] = 0;

    for (int i = 0; i < 300; i++)
        if (B[i] > A[i])
        {
            puts ("NO");return 0;
        }
    puts ("YES");


    return 0;
}




// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Nov 29, 2010 7:10:24 PM
// contest: 43
// link: /contest/43/submission/201254
// time: 30 ms
// verdict: Accepted
// problem: 43B - Letter
// ID: 201254
// downloaded by very stupid script
