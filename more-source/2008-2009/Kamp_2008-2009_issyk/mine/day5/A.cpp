#include <iostream>
#include <fstream>

using namespace std;

template<class T>
void downHeap(T a[], long k, long n,T b[],T c[]) {
  T new_elem,new_elem2,new_elem3;
  long child;
  new_elem = a[k];
  new_elem2= b[k];
  new_elem3=c[k];
  while(k <= n/2) {
    child = 2*k;
    if( child < n && a[child] < a[child+1] )
    child++;
    if( new_elem >= a[child] ) break;
    a[k] = a[child];
    b[k]=b[child];
    c[k]=c[child];
    k = child;
  }
  a[k] = new_elem;
  b[k]=new_elem2;
  c[k]=new_elem3;
}

template<class T>
void heapSort(T a[], long size,T b[],T c[]) {
  long i;
  T temp;
  for(i=size/2-1; i >= 0; i--) downHeap(a, i, size-1,b,c);
  for(i=size-1; i > 0; i--) {
    temp=a[i]; a[i]=a[0]; a[0]=temp;
    temp=b[i]; b[i]=b[0]; b[0]=temp;
    temp=c[i]; b[i]=b[0]; b[0]=temp;
    downHeap(a, 0, i-1,b,c);
  }
}


main () {
ifstream fin("a.in");
ofstream fout("a.out");

    int N,M;
    cin>>N>>M;
    /*int a[N][N];*/
    //for(int i=0;i<N;i++){for(int j=0;j<N;j++){a[i][j]=10001;}}
    int rebro[N],cor[N],cor2[N];
    for(int i=0;i<N;i++){rebro[i]=10001;}

    for(int i=0;i<M;i++){
        int t1,t2,ves;
        cin>>t1>>t2>>ves;
 /*       a[t1-1][t2-1]=ves;
        a[t2-1][t1-1]=ves;
   */     rebro[i]=ves;
        cor[i]=t1-1;
        cor2[i]=t2-1;
        }
     int colour[N],min=10001;
     bool linked[N],sum=0;
     for(int i=0;i<N;i++){colour[i]=i;}

    heapSort(rebro,N,cor,cor2);

    for(int i=0;i<N;i++){
        if(colour[cor[i]]==colour[cor2[i]])continue;
        if(colour[cor[i]]!=colour[cor2[i]]){
            int t_1=colour[cor2[i]];
            for(int j=0;j<N;j++){
            colour[j]=t_1;}
            sum+=rebro[i];}
            cout<<i<<" "<<rebro[i]<<" ";
        }
cout<<endl<<sum;

fin.close();
fout.close();
return 0;
}
