#include<iostream>
using namespace std;
int c2[12][2]={1,3,
               1,4,
               2,3,
               2,4,
               1,5,
               1,6,
               2,5,
               2,6,
               3,5,
               3,6,
               4,5,
               4,6},  c3[8][3]={1,3,5,
                                1,3,6,
                                1,4,5,
                                1,4,6,
                                2,3,5,
                                2,3,6,
                                2,4,5,
                                2,4,6};
bool f(int a[])
{
     for(int i=0;i<12;i++)
      if(a[c2[i][0]-1]==a[c2[i][1]-1]) return true;
     for(int i=0;i<8;i++)
      if(a[c3[i][0]-1]==a[c3[i][1]-1] && a[c3[i][0]]==a[c3[i][2]]) return true;
       return false;
}                 
bool read()
{
     int a[6];
      for(int i=0;i<6;i++)
       cin>>a[i];
        return f(a);
}                               
int main()
{
    freopen("cube.in","r",stdin);
     freopen("cube.out","w",stdout);
      int n;
       cin>>n;
        for(int i=1;i<=n;i++)
         if(read()) cout<<"Yes"<<'\n';
          else cout<<"No"<<'\n';
           return 0;
}                                           
