#include <iostream>
#include <fstream>

using namespace std;

template<class T>
void quickSortR(T* a, long N) {
  long i = 0, j = N;
  T temp, p;

  p = a[ N>>1 ];do {
    while ( a[i] < p ) i++;
    while ( a[j] > p ) j--;

    if (i <= j) {
      temp = a[i]; a[i] = a[j]; a[j] = temp;
      i++; j--;
    }
  } while ( i<=j );
  if ( j > 0 ) quickSortR(a, j);
  if ( N > i ) quickSortR(a+i, N-i);
}

main () {
ifstream fin("kth.in");
ofstream fout("kth.out");

    int N,K;
    fin>>N>>K;
    int a[N];
    for(int i=0;i<N;i++){fin>>a[i];}

    quickSortR(a,N-1);
    fout<<a[K-1];


fin.close();
fout.close();
return 0;
}
