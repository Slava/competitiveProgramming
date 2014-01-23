#include <iostream>
#include <cstdio>
using namespace std;
int pos[999] , used[999];
int n , x;
void generate(int k , const int e)
{
    int i , j;
    if(k == e)
    {
        x++;
        for(i = 1; i <= k; i++)
        {
            cout << pos[i] << " ";
        }
        cout << endl;
    }
    else
    for(j = 1; j <= n; j++)
    {
        if(used[j] == 0 && pos[k] < j)
        {
            used[j] = 1;
            pos[k + 1] = j;
            generate(k + 1 , e);
            used[j] = 0;
        }
    }
}
int main()
{
    freopen("A.in" , "r" , stdin);
    freopen("A.out" , "w" , stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        generate(0 , i);
    }
}
