// Kim Vyacheslav KarKTL
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int n;
double C, a[10];

void r (vector<double> A)
{
    if (A.size() == 1)
        if (fabs(A[0] - C) <= 0.01)
        {
            puts ("YES");
            exit(0);
        }
        else return;

    vector <double> B;
    for (int i = 0; i < A.size(); i++)
        for (int j = i + 1; j < A.size(); j++)
        {
            B.clear();
            for (int k = 0; k < A.size(); k++)
                if (k != i && k != j)
                    B.push_back(A[k]);
            B.push_back (A[i] + A[j]);
            r(B);
            B.pop_back();
            B.push_back ((A[i] * A[j]) / (A[i] + A[j]));
            r (B);
        }
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%d%lf", &n, &C);
    for (int i = 0; i < n; i++)
        scanf ("%lf", &a[i]);

    vector <double> A(a, a + n);
    r (A);
    puts ("NO");

    return 0;
}

