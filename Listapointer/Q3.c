/*Faça um programa que tenha uma função ordena que recebe um vetor de inteiros e ordene os valores. A função main deve ler do usuário os valores (ex. 5 valores), chamar a função ordena, e depois imprimir os valores ordenados.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define tam 5

void ordena(int *v){
  int i, j, aux;
  for(i=1; i<tam; i++){
    aux = v[i];
    j = i-1;
    while(v[j] > aux){
        v[j+1] = v[j];
        j = j-1;
    }
    v[j+1] = aux;
    
  }
}

int main(){
  int v[tam];
  int i;
  setlocale(LC_ALL, "Portuguese");
  printf("Digite os valores:\n");
  for(i = 0; i < tam; i++){
    printf("v[%d] = ", i+1);
    scanf("%d", &v[i]);
  }
  ordena(v);
  printf("Os valores ordenados são: ");
  for(i = 0; i < tam; i++){
    printf("%d ", v[i]);
  }
  printf("\n");
  return 0;
}