#include<fstream>
#include<cmath>
using namespace std;
double MIN(double x1,double y1,double x2,double y2)
{
    return  fabs(x1-x2)+fabs(y1-y2);
}    
int main()
{
    ifstream fin("A.in");
     ofstream fout("A.out");
      double x[106],y[106],n,a[106];
       fin>>n;
    
         for(int i=1;i<=n;i++)
          { fin>>x[i]>>y[i]; a[i]=i; }
          
        for(int i=1;i<=n;i++)
         {
               double min=2147483647; 
                for(int j=1;j<=n;j++)
                 if(j!=i) 
                  {
                       double t=MIN(x[i],y[i],x[j],y[j]);
                        if(min>t) { min=t; a[i]=j; }
                       }
            }          
       for(int i=1;i<=n;i++)
        fout<<a[i]<<" ";      
         fin.close();fout.close();
}            
