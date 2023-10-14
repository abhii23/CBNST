#include <stdio.h>
#include <math.h>
int main(){
  
  // u = 4(x^2 y^3)/ z^4;
  // x = y = z = 1     and err in x = y = z = 0.001;
  float x,y,z,err_x, err_y, err_z;
  x = y = z = 1;
  err_x  = err_y = err_z = 0.001;
  
  
  float true_v =  4 * (pow(x, 2) * pow(y, 3)) / pow(z, 4);
  
  float par_x = 8   * x          * pow(y, 3)  * err_x / pow(z, 4);
  float par_y = 12  * pow(x, 2)  * pow(y, 2)  * err_y / pow(z, 4); 
  float par_z = -16 * pow(x, 2)  * pow(y, 3)  * err_z / pow(z, 5);
  
  float abs_e = fabs(par_x + par_y + par_z);
  
  
  float rel_e = abs_e/true_v;
  float per_e = rel_e * 100;
  
  //printf("par x, y, z %f %f %f \n", par_x, par_y, par_z);
  
  printf("Absolute Error: %f \n", abs_e);
  
  printf("Relative Error: %f \n", rel_e);
  
  printf("Percentage Error: %f%%\n", per_e);
}