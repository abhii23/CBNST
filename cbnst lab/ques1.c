#include<stdio.h>
#include<math.h>
int main(){
	int x,y,z;
	x=y=z=1;
	float dex,dey,dez;
	dex=dey=dez=0.001;
	int u=4*pow(x,2)*pow(y,3)/pow(z,4);
	float dx=8*x*pow(y,3)*dex/pow(z,4);
	float dy=12*pow(x,2)*pow(y,2)*dey/pow(z,4);
	float dz=16*pow(x,2)*pow(y,3)*dez/pow(z,5);
	float du=dx+dy-dz;
	printf("the absolute error is:%0.3f\n",du);
	printf("the relative error is:%0.3f\n",du/u);
	printf("the percentage error is:%0.3f\n",du*100/u);
}

