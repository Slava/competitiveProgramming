#include <iostream>
using namespace std;


int main ()
{
    freopen("cube.in","r",stdin);
    freopen("cube.out","w",stdout);

    int n, a[11][6];
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<6;j++)
            cin>>a[i][j];
     if(a[i][0]==a[i][5])cout<<"YES"<<endl;
else if(a[i][0]==a[i][4])cout<<"YES"<<endl;
else if(a[i][0]==a[i][3])cout<<"YES"<<endl;
else if(a[i][0]==a[i][2])cout<<"YES"<<endl;
else if(a[i][3]==a[i][5])cout<<"YES"<<endl;
else if(a[i][3]==a[i][4])cout<<"YES"<<endl;
else if(a[i][3]==a[i][1])cout<<"YES"<<endl;
else if(a[i][1]==a[i][5])cout<<"YES"<<endl;
else if(a[i][1]==a[i][4])cout<<"YES"<<endl;
else if(a[i][1]==a[i][2])cout<<"YES"<<endl;
else if(a[i][2]==a[i][5])cout<<"YES"<<endl;
else if(a[i][2]==a[i][4])cout<<"YES"<<endl;
else cout<<"NO"<<endl;
    }


    return 0;
}
