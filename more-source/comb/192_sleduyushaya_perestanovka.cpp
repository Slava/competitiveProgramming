#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int>a;
    int n, i;
    scanf("%d", &n);
    a.resize(n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    next_permutation(a.begin(), a.end());
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);


    return 0;
}
