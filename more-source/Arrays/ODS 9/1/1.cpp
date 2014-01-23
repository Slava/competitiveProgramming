#include <fstream.h>
#include <iostream.h>
int main () {
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");


int N,hold;
fin>>N;
int Arrey[N][3];
	for (int j=0;j<N;j++){
		for (int i=0;i<3;i++){
		fin>>Arrey[j][i];
		}
	}
for (int pass=1;pass<N;pass++){
	for (int i=0;i<N-1;i++){
		if (Arrey[i][0]>Arrey[i+1][0]){
		hold=Arrey[i][0];
		Arrey[i][0]=Arrey[i+1][0];
		Arrey[i+1][0]=hold;

		hold=Arrey[i][1];
		Arrey[i][1]=Arrey[i+1][1];
		Arrey[i+1][1]=hold;

		hold=Arrey[i][2];
		Arrey[i][2]=Arrey[i+1][2];
		Arrey[i+1][2]=hold;

		}
	}
}

for (int pass=1;pass<N;pass++){
	for (int i=0;i<N-1;i++){
		if (Arrey[i][0]==Arrey[i+1][0]){
			if (Arrey[i][1]>Arrey[i+1][1]){
			hold=Arrey[i][0];
			Arrey[i][0]=Arrey[i+1][0];
			Arrey[i+1][0]=hold;

			hold=Arrey[i][1];
			Arrey[i][1]=Arrey[i+1][1];
			Arrey[i+1][1]=hold;

			hold=Arrey[i][2];
			Arrey[i][2]=Arrey[i+1][2];
			Arrey[i+1][2]=hold;
			}
		}
	}
}

for (int pass=1;pass<N;pass++){
	for (int i=0;i<N-1;i++){
		if ((Arrey[i][1]==Arrey[i+1][1])&&(Arrey[i][0]==Arrey[i+1][0])){
			if (Arrey[i][2]>Arrey[i+1][2]){
			hold=Arrey[i][0];
			Arrey[i][0]=Arrey[i+1][0];
			Arrey[i+1][0]=hold;

			hold=Arrey[i][1];
			Arrey[i][1]=Arrey[i+1][1];
			Arrey[i+1][1]=hold;

			hold=Arrey[i][2];
			Arrey[i][2]=Arrey[i+1][2];
			Arrey[i+1][2]=hold;
			}
		}
	}
}

for (int i=0;i<N;i++){
	for (int j=0;j<3;j++){
	fout<<Arrey[i][j]<<" ";
	}
fout<<endl;
}



fin.close();
fout.close();
return 0;
}
