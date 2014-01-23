#include<iostream.h>
#include<fstream.h>
#include <string.h>
ifstream fin ("a.in");
ofstream fout ("a.out");
int main () {
   int N,M,L;
   const int size=250,max=100;
   cin>>N;
   //tegi
   char tegs[max][size];
   for(int i=0;i<N;i++){
   	cin.getline(tegs[i],250,'\n');
   }
   //stroki
   cin>>M;
   char strings[max][size];
   for (int i=0;i<M;i++){
   	cin.getline (strings[i],250,'\n');
   }
   //tekst
   cin>>L;
   char search[max][size];
   for (int i=0;i<L;i++){
   	cin.getline(search[i],250,'\n');
   }
   //obrabotka
   for(int isearch=0;isearch<L;isearch++){
   	for(int istr=0;istr<M;istr++){
            for(int i=0;i<250;i++){
               

		if(strings[istr][i]=='<'){int minus=0;
                 if(strings[istr][i+1]=='/'){
                  for(int iteg=0;iteg<N;iteg++){
                    int sizestr=strlen(teg[iteg]);
                    for(int icheck=0;icheck<sizestr;icheck++){
                     if (strings[istr][i+icheck+2]!=teg[iteg][icheck])break;
		     if((icheck==sizestr-1)&&(strings[istr][i+icheck+2]==teg[iteg][icheck]))minus=sizestr+3;
		    }

		  }

		 }
                 else{
                   for(int iteg=0;iteg<N;iteg++){
                    int sizestr=strlen(teg[iteg]);
                    for(int icheck=0;icheck<sizestr;icheck++){
                      if(strings[istr][i+icheck+1]!=teg[iteg][icheck])break;
		      if((icheck==sizestr-1)&&(strings[istr][i+icheck+1]==teg[iteg][icheck]))minus=sizestr+2;
		    }
		   }
		 }
	       i+=minus;continue;}

if(strings[istr][i]==search[isearch][0]){
	for(int j=0;j<strlen(search[isearch]);j++){

	   if(strings[istr][i+j]!=search[isearch][j])break;
	   if ((strings[ist][i+strlen(search[isearch])-1]==search[isearch][strlen(search[isearch])-1]))&&(strlen(search[isearch])-1==j))
}

}
	    }

	}

   }


return 0;
}