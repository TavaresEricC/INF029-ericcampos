/*Crie um programa que tenha uma função ler3Numeros. Essa função deve ler três números do
usuário e retornar os três números. A função main deve imprimir esses três números. Utilize vetor
para fazer o retorno.*/

#include <stdio.h>
#include <locale.h>
#define tam 3

void ler3Numeros(int a[tam]){
  for(int i = 0; i<3; i++){
    printf("%dº número: ", i+1);
    scanf("%d", &a[i]);
  }
}

int main(){
  int num[tam], i;

  printf("Digite três números para serem exibidos:\n");
  ler3Numeros(num);
  for(i=0; i<3; i++){
    printf("%d\t", num[i]);
  }
  printf("\n");
}