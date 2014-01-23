#include <iostream>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    long a[3000], n, k, i, j, b[11];
    cin >> n;
    a[0] = 0;
    for(i = 0; i < n; i++ )
        cin >> b[i];
    cin >> k;
    for(i = 1; i <= k; i++)
    {
        a[i%3000] = 10000000;
        for(j = 0; j < n; j++)
            if((i - b[j])%3000>=0)a[i%3000] = min(a[i%3000], a[(i - b[j])%3000]+1);

    }

    if(a[k%3000]>1000000)cout<<"-1";
    else cout<<a[k%3000];

    return 0;
}
