/*Crie um programa que leia um número n de idades, e imprima a todas idades maior que a média delas*/

#include <stdio.h>
#include <locale.h>

int main(){
  setlocale(LC_ALL, "Portuguese");
  int n, i, soma = 0, media ; 
  
  printf("Digite o número de idades que deseja comparar (valor inteiro positivo): ");
  scanf("%d", &n);
  
  int idade[n];

  printf("\nDigite as idades.\n\n");

  for(i=0; i<n; i++){
    printf("idade %d: ", i+1);
    scanf("%d", &idade[i]);
  }
  
  printf("\n\nIdade(s) maior(es) que a média\n");
  for(i=0;i<n;i++){
    soma = soma + idade[i];
  }
  media = soma/n;

  for(i=0; i<n; i++){
    if(idade[i] > media){
      printf("%d\t",idade[i]);
    }
  }
  printf("\n");
}