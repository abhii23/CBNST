//Euler's Method
#include <stdio.h>
float f (float x,float y){
    return x+y;
}
int main(){
    float a,b,x,y,h,xn,k;
    printf("\n Enter x0,y0,xn,h: ");
    scanf("%f%f%f%f",&x,&y,&xn,&h);

    printf("\n x\t y\n");
    while(x<=xn){
        k=h*f(x,y);
        y+=k;
        x+=h;
        printf("%.3f\t%.3f\n",x,y);
    }
}