#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

char C[2000];
char base[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ",
    rebase[255];
bool some;
int main(){
	int A, B;
	char ch;
    scanf ("%d ", &A);
    if (scanf ("%d\n", &B) == 1)
    {some = 1;}else scanf("%c\n", &ch);
    for (int i = 0; i < 26; i++)
        rebase[base[i]] = i;
    gets(C);
	long long r = 1, N = 0;
	int i = strlen(C) - 1;
   	 for (; i >= 0; i--, r *= A)
   	     N += r * rebase[C[i]];
   if(some){
   string out;
  	  if (!N)
   	     cout << 0;
   	 while (N)
   	 {
   	     out.push_back(base[N%B]);
   	     N /= B;
   	 }
   	 for (i = out.size() - 1; i >= 0; i--)
       	 cout << out[i];
    	return 0;
    }
   string s = "IIIVIXXXLXCCCDCMMM";
   long long n, c[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
   n = N;
   for(i=12; i>-1;n%=c[i], i--)
  		 cout<< (n/c[i]>0 ? s.substr(i+(i+3)/4, i%4 ? (i-2)%4 ? 2 : 1 : n/c[i]) : "");
}




// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Feb 23, 2011 6:29:01 AM
// contest: 61
// link: /contest/61/submission/299844
// time: 30 ms
// verdict: Accepted
// problem: 61C - Capture Valerian
// ID: 299844
// downloaded by very stupid script
