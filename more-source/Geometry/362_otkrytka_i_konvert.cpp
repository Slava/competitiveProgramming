#include <iostream>
#define EPS 1e-9
#define M_PI 3.141592653589793
using namespace std;
bool OK(double AB,double BC,double Wk,double Hk){
	if(BC>AB) swap(AB,BC);
	if(Hk>Wk) swap(Hk,Wk);
	if(BC>Hk) return false;

	if(Hk>=BC && Wk>=AB)
		return true;
	double AF=Hk;
	double AC=sqrt(AB*AB+BC*BC);
	double FC=sqrt(AC*AC-AF*AF);
	double CAB=atan(BC/AB);
	double FAC=atan(FC/AF);
	double BAF=CAB+FAC;
	double BAE=M_PI/2.0 - BAF;
	double GE=BC*sin(BAE)+AB*cos(BAE);
        if(GE<Wk-EPS || fabs(GE-Wk)<EPS) return true;
	return false;
}


int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
        double AB,BC,Wk,Hk;
	scanf("%lf%lf%lf%lf",&AB,&BC,&Wk,&Hk);
	if(OK(AB,BC,Wk,Hk))
		printf("Possible");
	else
	        printf("Impossible");
return 0;
}
