#include <stdio.h>
#include <stdlib.h>


void ast( char caractere, int tam){
  for(int i=1; i<tam; i++)
    printf("%c", caractere);
  printf("\n");
}
int main(){
  int i;
  ast('#', 20);
  printf("Números de 1 a 5\n");
  ast('#',20);
}