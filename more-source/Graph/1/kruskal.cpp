#include <iostream>

using namespace std;

#define mp make_pair
#define f first
#define s second

//gloabal'nye peremennye
pair<int, pair<int,int> >a[100],b[100];//norm derevo i gotovoe
int n,m,r[1000],p[1000];

//nayti predka
int Find (int x){//x = vershyna
	if(p[x]!=x)//esli on ne yavlyaetsya predkom
	{p[x]=Find(p[x]);}//prodolzhaem poisk predka i balansiruem derevo
	return p[x];
}

//soedinyaem vershiny
void Union (int x,int y){//x & y - vershyny, kotorye soedinyaem
	x=Find(x);//nahodim ih predkov
	y=Find(y);//i soedinyaem predkov
	if(r[x]>r[y])//smotrim rank
	{p[y]=x;}//soedinyam vershyny
	else {//r[y]>=r[x]
		p[x]=y;
		if(r[x]==r[y])r[y]++;
	}
}

int main () {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int l,z,w;
	cin>>n;//kol-vo vershyn
	cin>>m;//kol-vo reber

	//init
	for(int i=0;i<n;i++){
		r[i]=1;p[i]=i;
	}

	for(int i=0;i<m;i++){
		cin>>l>>z>>w;
		a[i]=mp(w,mp(l,z));
	}
	sort(a,a+m);

int count=0;

	for(int i=0;i<m;i++){
		if(Find(a[i].s.f)!=Find(a[i].s.s)){//esli predki raznye
			Union(a[i].s.f,a[i].s.s);//soedinyaem
			b[count].f=a[i].f;
			b[count].s.f=a[i].s.f;
			b[count].s.s=a[i].s.s;
			count++;
		}
	}

	for(int i=0;i<count;i++){
		cout<<b[i].s.f<<" "<<b[i].s.s<<" "<<b[i].f<<endl;
	}

	return 0;
}
