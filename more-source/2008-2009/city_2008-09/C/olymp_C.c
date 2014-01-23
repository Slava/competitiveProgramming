#include <fstream.h>
int main () {
    ifstream fin ("C.in");
    ofstream fout ("C.out");
int N,M;
fin>>N>>M;
int q[N];
int p[M];
int maxb=0,maxm=0;
//opredelenie stoimostei blokov
for (int i=0;i<N;i++)
{
    fin>>q[i];
}

//opredelenie stoimostei monitorov
for (int j=0;j<M;j++)
{
    fin>>p[j];
}
//kolichestvo celyh kompov
int kolvo;
if (N<M){
fout<<N<<" ";
kolvo=N;}

if (M<N){
fout<<M<<" ";
kolvo=M;}

if (M==N){
fout<<M<<" ";
kolvo=M;}
//opredelenie stoimosti max
int sum=0,ttt=0;
for (int temp=1;temp<=kolvo;temp++)
{maxb=0;
maxm=0;

    for (int i=0;i<N;i++)
    {
    if (maxb<q[i]){
    maxb=q[i];
    }
    }
            for (int i=0;i<N;i++)
        {
            if (maxb==q[i])
            {
                q[i]=0;
            }
        }
    for (int j=0;j<M;j++)
    {

    if (maxm<p[j]){
    maxm=p[j];
    }
    }

        for (int j=0;j<M;j++)
        {
            if (maxm==p[j])
            {
                p[j]=0;
            }
        }
        ttt=maxb*maxm;
 sum=sum+ttt;
}

fout<<sum;

    fin.close();
    fout.close();

return 0;
}
