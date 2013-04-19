#include <cstdio>

#define max(a,b) (a<b?b:a)
int n,m,a[500][500],i,j,k,l,p,maxi=-(1<<30);
int main()
{
    scanf("%d", &n); m = n;
	if(!n&&!m){printf("0");return 0;}
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            scanf("%d",&a[i][j]);
            if(!i&&j)a[i][j]=a[i][j]+a[i][j-1];
            else if(i&&!j)a[i][j]=a[i][j]+a[i-1][j];
            else if(i&&j)a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            for(k=i;k<n;k++)
                for(l=j;l<m;l++)
                {
                    p=a[k][l];
                    if(j>0)p-=a[k][j-1];
                    if(i>0)p-=a[i-1][l];
                    if(i>0&&j>0)p+=a[i-1][j-1];
                    maxi=max(maxi,p);
                }

   printf("%d", maxi);

    return 0;
}
