#include <iostream>
#include <fstream>

using namespace std;

  ifstream fin ("a.in");
    ofstream fout ("a.out");
/*template<class T>
int BinarySearch (T a[],long start,long size,long searchkey){
    if(((size-start)!=0)&&((size-start)!=1)){
    if (a[(size-start)/2]==searchkey){fout<<"YES\n";return 0;}
    if (a[(size-start)/2]<searchkey)BinarySearch(a,((size-start)/2),size,searchkey);
    if (a[(size-start)/2]>searchkey) BinarySearch(a,start,((size-start)/2),searchkey);}

    if(((size-start)==0)||((size-start)==1)) {
        if(a[size]==searchkey){fout<<"YES\n";return 0;}
        if(a[start]==searchkey){fout<<"YES\n";return 0;}
        if(a[start+1]==searchkey){fout<<"YES\n";return 0;}
        else{ fout<<"NO\n";return 0;}
    }
    }
*/

template <class T>
int binary (T b[], long low, int high, int size,long searchkey){
    int middle;
    while(low<=high){
        middle=(low+high)/2;
        if (searchkey==b[middle]){fout<<"YES\n";return middle;}

        else{ if(searchkey<b[middle])
                high = middle-1;
             else low=middle+1;}

        }
    fout<<"NO\n";
    return -1;
    }

main () {


    int N,K;
    fin>>N>>K;
    long a[N];
    long s[K];

    for(int i=0;i<N;i++){
        fin>>a[i];
        }
    int mid=N>>0;
    for(int i=0;i<K;i++){
        fin>>s[i];
        }
    for(int i=0;i<K;i++){
        binary(a,0,N-1,N,s[i]);
        }
    fin.close();
    fout.close();

    return 0;
    }
