#include <iostream.h>
int main () {
    int N;
    int b[9]={0};
    cout<<"Skol'ko prodavcov? ";
    cin>>N;
    int array[N];
    float temp;
    for (int i=0;i<N;i++)
        {
        array[i]=250;
        }
    for (int i=0;i<N;i++)
        {
        temp=0;
        cout<<"Potokovy dohod "<<i+1<<" prodovca: ";
        cin>>temp;
        temp=temp*100/9;
        array[i]+=temp;
            if ((array[i]<=299)&&(array[i]>=200))
                {
                b[0]++;
                }
            if ((array[i]<=399)&&(array[i]>=300))
                {
                b[1]++;
                }
            if ((array[i]<=499)&&(array[i]>=400))
                {
                b[2]++;
                }
            if ((array[i]<=599)&&(array[i]>=500))
                {
                b[3]++;
                }
            if ((array[i]<=699)&&(array[i]>=600))
                {
                b[4]++;
                }
            if ((array[i]<=799)&&(array[i]>=700))
                {
                b[5]++;
                }
            if ((array[i]<=899)&&(array[i]>=800))
                {
                b[6]++;
                }
            if ((array[i]<=999)&&(array[i]>=900))
                {
                b[7]++;
                }
            if (array[i]>=1000)
                {
                b[8]++;
                }
        }




        cout<<"$200 - $299 :";
        cout<<b[0]<<endl;
        cout<<"$300 - $399 :";
        cout<<b[1]<<endl;
        cout<<"$400 - $499 :";
        cout<<b[2]<<endl;
        cout<<"$500 - $599 :";
        cout<<b[3]<<endl;
        cout<<"$600 - $699 :";
        cout<<b[4]<<endl;
        cout<<"$700 - $799 :";
        cout<<b[5]<<endl;
        cout<<"$800 - $899 :";
        cout<<b[6]<<endl;
        cout<<"$900 - $999 :";
        cout<<b[7]<<endl;
        cout<<"Bol'she $1000 :";
        cout<<b[8]<<endl;



    return 0;
    }
