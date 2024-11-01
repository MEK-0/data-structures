 /* Algoritma analizi için 

  time complex. hesaplama için 

*/

#include<stdio.h>
#include<time.h>   // **********



int main(){

  clock_t start,end;
  double time ; 

  start=clock();  

  /*

   KOD KISMI
  
  */

  end = clock();

  time = (double) (end-start) / CLOCKS_PER_SEC;  
  printf("Execution Time \n %fs",time);

  
  return 0;
}
