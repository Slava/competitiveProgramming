#include <iostream>
#include <cmath>
using namespace std;

struct dot{
    double x,y;
    };

int main()
{
    dot a[60000];
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i].x>>a[i].y;
    double sum=0;
    for(i=0;i<n;i++)
        sum+=a[i].x*(a[(i+1)%n].y-a[(i+2)%2].y);
    sum=fabs(sum)/2;
    cout<<sum;

}
