#include <iostream>

using namespace std;

int main ()
{
int a[200], n, max = -9999999, I, J, K;
cin >> n;
for (int i = 0; i < n; i++)
    cin >> a[i];
for (int i = 0; i < n; i++)
    for (int j = i+1; j < n; j++)
        for (int k = j+1; k < n; k++)
            if (max < a[i] * a[j] * a[k]){
                max = a[i] * a[j] * a[k];
                I = i; J = j; K = k;
           }
cout << a[I] << ' '<< a[J] << ' ' << a[K];

}