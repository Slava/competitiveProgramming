// код был нагло скопирован с сайта емакса
// извините, пожалуйста
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int N = 1000000,INF = 1000000000;
int t[N][26], l[N], r[N], p[N], s[N], tv, tp, ts=2;
string a;

void ukkadd (int c) {
suff:;
	 if (r[tv]<tp) {
		 if (t[tv][c]==-1) { t[tv][c]=ts;  l[ts]=a.size()-1;  r[ts]=INF;
			 p[ts++]=tv;  tv=s[tv];  tp=r[tv]+1;  goto suff; }
			 tv=t[tv][c]; tp=l[tv];
	 }
	 if (tp==-1 || c==a[tp]) tp++; else {
		 l[ts+1]=a.size()-1;  r[ts+1]=INF;  p[ts+1]=ts;
		 l[ts]=l[tv];  r[ts]=tp-1;  p[ts]=p[tv];  t[ts][c]=ts+1;  t[ts][a[tp]]=tv;
		 l[tv]=tp;  p[tv]=ts;  t[p[ts]][a[l[ts]]]=ts;  ts+=2;
		 tv=s[p[ts-2]];  tp=l[ts-2];
		 while (tp<=r[ts-2]) {  tv=t[tv][a[tp]];  tp+=r[tv]-l[tv]+1;}
		 if (tp==r[ts-2]+1)  s[ts-2]=tv;  else s[ts-2]=ts; 
		 tp=r[tv]-(tp-r[ts-2])+2;  goto suff;
	 }
}
 
void build (string txt) {
	s[0]=1;
	l[0]=r[0]=l[1]=r[1]=-1;
	memset (t, -1, sizeof t);
	fill(t[1],t[1]+26,0);
	for (size_t i=0; i<txt.length(); ++i)
		ukkadd (txt[i] - 'a');
}
