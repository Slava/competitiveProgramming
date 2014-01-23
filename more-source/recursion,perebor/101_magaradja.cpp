#include <fstream>

using namespace std;

int n,k,a[20][20],o,s=0;
bool h[20];
int p(int w,int z)
{
    if(z>k)return 0;
    int s=0;
    for(int i=w;i<n;i++)
        for(int j=0;j<n;j++)
        {
            bool d=0;
            for(int o=1;o<n;o++)
            {
                if(j-o>=0&&i-o>=0)
                    if(a[i-o][j-o]){d=1;break;}
                if(j+o<n&&i+o<n)
                    if(a[i+o][j+o]){d=1;break;}
                if(j+o<n&&i-o>=0)
                    if(a[i-o][j+o]){d=1;break;}
                if(j+o>=0&&i+o<n)
                    if(a[i+o][j-o]){d=1;break;}
            }
            if(i>0)if(a[i-1][j-2]||a[i-1][j+2])d=1;
            if(i>1)if(a[i-2][j-1]||a[i-2][j+1])d=1;
            if(h[j])d=1;
            if(!d)
                if(z==k)s+=1;
                else {h[j]=a[i][j]=1;
                    s+=p(i+1,z+1);
                    h[j]=a[i][j]=0;}
        }

    return s;
}

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    cin>>n>>k;
    cout<<p(0,1);

}
