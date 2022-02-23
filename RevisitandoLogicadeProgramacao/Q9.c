/*Faça um programa que leia 10 números do usuário e informe quais deles são primos. Além disso, mostre a soma de todos os números primos existentes.*/
#include <stdio.h>
#define TAM 10

int main(){
  int i, n[TAM], aux=0, div, primo;
  
  for(i=0; i<TAM; i++){
    printf("Digite o %dº número: ", i+1);
    scanf("%d", &n[i]);
  }
  printf("\nNúmeros digitados que são primos:\n\n");
  for(i=0; i<TAM; i++){
    primo = 1;
  if(n[i]<=1){
    primo=0;
  }

  for(div = 2; div<=n[i]/2 && primo==1; div++){
    if(n[i]%div==0){
      primo = 0;
    }
  }

  if(primo == 1){
    printf("\t %d", n[i]);
  }
  }

  for(i=0; i<TAM; i++){
    primo = 1;
  if(n[i]<=1){
    primo=0;
  }

  for(div = 2; div<=n[i]/2 && primo==1; div++){
    if(n[i]%div==0){
      primo = 0;
    }
  }

  if(primo == 1){
    aux = aux + n[i];
  }
  }
  printf("\n\nA soma dos números primos digitados é igual a: %d.\n", aux);
  }