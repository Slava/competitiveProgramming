#include <iostream>

using namespace std;

int a[10001][3],d[10001],k,n,m,i,j,l=30000, was;
int main() {
    cin>>n>>m;

    d[1]=0;
    for(i=2;i<=n;i++)d[i]=l;

    for(i=1;i<=m;i++)
        for(j=0;j<3;j++)
            cin>>a[i][j];

	was = 1;
    for(j=1;j<n && was;j++) {
        was = 0;
		for(i=1;i<=m;i++)
            if (d[a[i][1]] > d[a[i][0]] + a[i][2]) {
				d[a[i][1]] = d[a[i][0]] + a[i][2];
				was = 1;
			}
	}

    for(i=1;i<=n;i++)
        if(d[i]>l/2)cout<<l<<' ';
        else cout<<d[i]<<' ';

    return 0;
}
